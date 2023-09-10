#include "ParseFile.h"

/*
 * CLASS: ParseFile.cpp
 *
 * Author: Michelle Li
 *
 * REMARKS: Implementation for reading the parsed file and executing the simulation. Parses file one line at a time WHILE printing and executing the
 * simulation of the restaurant. Most of the work of the file is done here, after being called by the main.
 *
 * ---------------------------------------------------------------------------------------
 */

ParseFile::ParseFile()
{} //empty constructor

ParseFile::ParseFile(string name, string ver) : fileName(name), version(stoi(ver)) {
    currTime = 0;
    readOrders = 0;
    totalOrders = 0;

} //initializer

/* ---------------------------------------------------------------------------------------
 *  read()
 *
 *  PURPOSE: Reads the input text one line at a time and uses it to run the simulation. Contains all 3 versions of the simulation within
 *  the method... First checks the version (1,2,3) and runs the simulation based on that. All simulations are extremely similar in
 *  code, except version 1 uses Queue, V2 uses Stack, and V3 uses PQPrice for its customer lists. All implementations use
 *  PQTime (time priority queue) for their Event Lists to access the earliest events.
 *  The code is split because of methods being named differently: Queues use dequeue, Stack used pop... etc. while they fundamentally
 *  do the same thing: remove the Node at top.
 *
 *  Each line read will call another method below to extract the information on each line and return the information as an Event with
 *  the data stored in its fields.
 *
 *  ---------------------------------------------------------------------------------------
 */

void ParseFile::read(){
    ifstream inputFile;
    inputFile.open(fileName);  // opening the file for reading

    string line;
    Event* current;

    if(version == 1){
        //---------------------------------- first come first serve -----------------------------------

        Queue* customerList = new Queue;
        PQTime* eventList = new PQTime();

        //casts to check instanceof:
        CompleteService* test1;
        Prepare* test2;

        getline(inputFile, line);

        current = parse(line);
        eventList->insert(current); //first arrival event
        currTime = current->getArrival(); //skip to FIRST arrival time

        while(getline(inputFile,line)){ //keep getting next line while the file is not over

            current = parse(line); //get next order

                if(eventList->peek() != nullptr){

                    while(eventList->peek() != nullptr &&
                    current->getArrival() > eventList->peek()->getItem()->getCompletionTime()){
                        //do all the events between current time and the next arrival about to be read

                        //figure out if it's an arrival OR preparing event OR departure event
                        test1 = dynamic_cast<CompleteService*>(eventList->peek()->getItem()); //try to cast to a CompleteService
                        test2 = dynamic_cast<Prepare*>(eventList->peek()->getItem()); //try to cast to a Prepare event

                        if(test1 != nullptr){
                            //if a completion event, complete the order

                            totalOrders++;
                            revenue += eventList->peek()->getItem()->getPrice(); //adding price of current order to total revenue
                            currTime = eventList->peek()->getItem()->getCompletionTime(); //set permanently to time
                            eventList->dequeue()->getItem()->message(currTime); //print out message for the event

                            //now, check next CUSTOMER in queue and try to prepare unexpired orders:
                            while(customerList->peek() != nullptr && customerList->peek()->getItem()->isExpired(currTime)){
                                customerList->dequeue();
                            } //quietly remove expired customers

                            if(customerList->peek() != nullptr){
                                //if customerList is not empty yet, create prepare event
                                eventList->insert(createPrep(customerList->dequeue()->getItem(), currTime));
                            }

                        } else if (test2 != nullptr){
                            //if is prepare event create departure event:

                            eventList->peek()->getItem()->message(currTime);
                            currTime = eventList->peek()->getItem()->getCompletionTime();
                            eventList->insert(createDeparture(eventList->dequeue()->getItem(), currTime));

                        } else {
                            //arrival event: just print and add to customer queue

                            eventList->peek()->getItem()->message(currTime);

                            //add new customer to customer list
                            customerList->insert(createCopy(eventList->peek()->getItem()));
                            currTime = eventList->dequeue()->getItem()->getCompletionTime();

                            if(eventList->peek() == nullptr) {
                                //get right to the next one if there's nothing happening in the event list after this
                                eventList->insert(createPrep(customerList->dequeue()->getItem(), currTime));

                            }
                        }
                    }
                    //ready to process current arrival:

                    eventList->insert(current); //first arrival event
                    currTime = current->getArrival(); //skip to current arrival time

                }

            }
            //finished reading new arrivals: finish up events in list:

            while(eventList->peek() != nullptr){
                test1 = dynamic_cast<CompleteService*>(eventList->peek()->getItem()); //try to cast to a CompleteService
                test2 = dynamic_cast<Prepare*>(eventList->peek()->getItem()); //try to cast to a Prepare event

                if(test1 != nullptr){
                    //if a completion event, complete the order

                    totalOrders++;
                    revenue += eventList->peek()->getItem()->getPrice(); //adding price of current order to total revenue
                    currTime = eventList->peek()->getItem()->getCompletionTime(); //set permanently to time
                    eventList->dequeue()->getItem()->message(currTime); //print out message for the event

                    //now, check next CUSTOMER in queue and try to prepare unexpired orders:
                    while(customerList->peek() != nullptr && customerList->peek()->getItem()->isExpired(currTime)){
                        customerList->dequeue();
                    } //quietly remove expired customers

                    if(customerList->peek() != nullptr){
                        //if customerList is not empty yet, create prepare event
                        eventList->insert(createPrep(customerList->dequeue()->getItem(), currTime));
                    }

                } else if (test2 != nullptr) {
                    //if prepare event create departure event:
                    eventList->peek()->getItem()->message(currTime);
                    eventList->insert(createDeparture(eventList->peek()->getItem(), currTime));
                    currTime = eventList->dequeue()->getItem()->getCompletionTime();
                } else {
                    //arrival event: just print and add to customer queue and
                    eventList->peek()->getItem()->message(currTime);
                    customerList->insert(createCopy(eventList->peek()->getItem()));
                    currTime = eventList->dequeue()->getItem()->getCompletionTime();

                    if(eventList->peek() == nullptr) {
                        //get right to the next one if there's nothing happening in the event list after this

                        eventList->insert(createPrep(customerList->dequeue()->getItem(), currTime));
                        //first loop needs to create preparation event
                    }
                }
            }

        } else if (version == 2){
        //-------------------------------last come first serve ---------------------------------------------

        Stack* customerList = new Stack;
        PQTime* eventList = new PQTime();

        //casts to check instanceof:
        CompleteService* test1;
        Prepare* test2;


        getline(inputFile, line);

        current = parse(line);

        eventList->insert(current); //first arrival event

        currTime = current->getArrival(); //skip to FIRST arrival time


        while(getline(inputFile,line)){ //keep getting next line while the file is not over

            current = parse(line); //get next order

            if(eventList->peek() != nullptr){

                while(eventList->peek() != nullptr &&
                      current->getArrival() > eventList->peek()->getItem()->getCompletionTime()){
                    //do all the events between current time and the next arrival about to be read

                    //figure out if it's an arrival OR preparing event OR departure event
                    test1 = dynamic_cast<CompleteService*>(eventList->peek()->getItem()); //try to cast to a CompleteService
                    test2 = dynamic_cast<Prepare*>(eventList->peek()->getItem()); //try to cast to a Prepare event

                    if(test1 != nullptr){
                        //if a completion event, complete the order

                        totalOrders++;
                        revenue += eventList->peek()->getItem()->getPrice(); //adding price of current order to total revenue
                        currTime = eventList->peek()->getItem()->getCompletionTime(); //set permanently to time
                        eventList->dequeue()->getItem()->message(currTime); //print out message for the event

                        //now, check next CUSTOMER in queue and try to prepare unexpired orders:
                        while(customerList->peek() != nullptr && customerList->peek()->getItem()->isExpired(currTime)){
                            customerList->pop();
                        } //quietly remove expired customers

                        if(customerList->peek() != nullptr){
                            //if customerList is not empty yet, create prepare event
                            eventList->insert(createPrep(customerList->pop()->getItem(), currTime));

                        }

                    } else if (test2 != nullptr){
                        //if is prepare event create departure event:

                        eventList->peek()->getItem()->message(currTime);
                        currTime = eventList->peek()->getItem()->getCompletionTime();
                        //CompleteService* test3 = createDeparture(eventList->peek()->getItem(), currTime);
                        eventList->insert(createDeparture(eventList->dequeue()->getItem(), currTime));

                    } else {
                        //arrival event: just print and add to customer queue and
                        eventList->peek()->getItem()->message(currTime);
                        customerList->insert(createCopy(eventList->peek()->getItem()));
                        currTime = eventList->dequeue()->getItem()->getCompletionTime();

                        if(eventList->peek() == nullptr) {
                            //get right to the next one if there's nothing happening in the event list after this

                            eventList->insert(createPrep(customerList->pop()->getItem(), currTime));
                            //first loop needs to create preparation event
                        }

                    } //already caught up on time for a departure order, so no need to dequeue again.

                } //emptying EventList for events that finish BEFORE the next arrival.

                //ready to process current arrival:

                eventList->insert(current); //first arrival event
                currTime = current->getArrival(); //skip to current arrival time

            }

        }
        //finished reading new arrivals: finish up events in list:

        while(eventList->peek() != nullptr){
            test1 = dynamic_cast<CompleteService*>(eventList->peek()->getItem()); //try to cast to a CompleteService
            test2 = dynamic_cast<Prepare*>(eventList->peek()->getItem()); //try to cast to a Prepare event

            if(test1 != nullptr){
                //if a completion event, complete the order

                totalOrders++;
                revenue += eventList->peek()->getItem()->getPrice(); //adding price of current order to total revenue
                currTime = eventList->peek()->getItem()->getCompletionTime(); //set permanently to time
                eventList->dequeue()->getItem()->message(currTime); //print out message for the event

                //now, check next CUSTOMER in queue and try to prepare unexpired orders:
                while(customerList->peek() != nullptr && customerList->peek()->getItem()->isExpired(currTime)){
                    customerList->pop();
                } //quietly remove expired customers

                if(customerList->peek() != nullptr){
                    //if customerList is not empty yet, create prepare event
                    eventList->insert(createPrep(customerList->pop()->getItem(), currTime));
                }

            } else if (test2 != nullptr) {
                //if prepare event create departure event:
                eventList->peek()->getItem()->message(currTime);
                eventList->insert(createDeparture(eventList->peek()->getItem(), currTime));
                currTime = eventList->dequeue()->getItem()->getCompletionTime();
            } else {
                //arrival event: just print and add to customer queue and
                eventList->peek()->getItem()->message(currTime);
                customerList->insert(createCopy(eventList->peek()->getItem()));
                currTime = eventList->dequeue()->getItem()->getCompletionTime();

                if(eventList->peek() == nullptr) {
                    //get right to the next one if there's nothing happening in the event list after this

                    eventList->insert(createPrep(customerList->pop()->getItem(), currTime));
                    //first loop needs to create preparation event
                }

            }
        }


    } else if (version == 3){
        //----------------------------------price priority -------------------------------------

        PQPrice* customerList = new PQPrice;
        PQTime* eventList = new PQTime();

        //casts to check instanceof:
        CompleteService* test1;
        Prepare* test2;

        getline(inputFile, line);

        current = parse(line);

        eventList->insert(current); //first arrival event
        currTime = current->getArrival(); //skip to FIRST arrival time


        while(getline(inputFile,line)){ //keep getting next line while the file is not over

            current = parse(line); //get next order

            if(eventList->peek() != nullptr){

                while(eventList->peek() != nullptr &&
                      current->getArrival() > eventList->peek()->getItem()->getCompletionTime()){
                    //do all the events between current time and the next arrival about to be read

                    //figure out if it's an arrival OR preparing event OR departure event
                    test1 = dynamic_cast<CompleteService*>(eventList->peek()->getItem()); //try to cast to a CompleteService
                    test2 = dynamic_cast<Prepare*>(eventList->peek()->getItem()); //try to cast to a Prepare event

                    if(test1 != nullptr){
                        //if a completion event, complete the order

                        totalOrders++;
                        revenue += eventList->peek()->getItem()->getPrice(); //adding price of current order to total revenue
                        currTime = eventList->peek()->getItem()->getCompletionTime(); //set permanently to time
                        eventList->dequeue()->getItem()->message(currTime); //print out message for the event

                        //now, check next CUSTOMER in queue and try to prepare unexpired orders:
                        while(customerList->peek() != nullptr && customerList->peek()->getItem()->isExpired(currTime)){
                            customerList->dequeue();
                        } //quietly remove expired customers

                        if(customerList->peek() != nullptr){
                            //if customerList is not empty yet, create prepare event
                            eventList->insert(createPrep(customerList->dequeue()->getItem(), currTime));
                        }

                    } else if (test2 != nullptr){
                        //if is prepare event create departure event:

                        eventList->peek()->getItem()->message(currTime);
                        currTime = eventList->peek()->getItem()->getCompletionTime();
                        eventList->insert(createDeparture(eventList->dequeue()->getItem(), currTime));

                    } else {
                        //arrival event: just print and add to customer queue and
                        eventList->peek()->getItem()->message(currTime);
                        customerList->insert(createCopy(eventList->peek()->getItem()));
                        currTime = eventList->dequeue()->getItem()->getCompletionTime();

                        if(eventList->peek() == nullptr) {
                            //get right to the next one if there's nothing happening in the event list after this

                            eventList->insert(createPrep(customerList->dequeue()->getItem(), currTime));
                            //first loop needs to create preparation event
                        }
                    }
                }
                //ready to process current arrival:

                eventList->insert(current); //first arrival event
                currTime = current->getArrival(); //skip to current arrival time

            }
        }
        //finished reading new arrivals: finish up events in list:

        while(eventList->peek() != nullptr){
            test1 = dynamic_cast<CompleteService*>(eventList->peek()->getItem()); //try to cast to a CompleteService
            test2 = dynamic_cast<Prepare*>(eventList->peek()->getItem()); //try to cast to a Prepare event

            if(test1 != nullptr){
                //if a completion event, complete the order

                totalOrders++;
                revenue += eventList->peek()->getItem()->getPrice(); //adding price of current order to total revenue
                currTime = eventList->peek()->getItem()->getCompletionTime(); //set permanently to time
                eventList->dequeue()->getItem()->message(currTime); //print out message for the event

                //now, check next CUSTOMER in queue and try to prepare unexpired orders:
                while(customerList->peek() != nullptr && customerList->peek()->getItem()->isExpired(currTime)){
                    customerList->dequeue();
                } //quietly remove expired customers

                if(customerList->peek() != nullptr){
                    //if customerList is not empty yet, create prepare event
                    eventList->insert(createPrep(customerList->dequeue()->getItem(), currTime));
                }

            } else if (test2 != nullptr) {
                //if prepare event create departure event:
                eventList->peek()->getItem()->message(currTime);
                eventList->insert(createDeparture(eventList->peek()->getItem(), currTime));
                currTime = eventList->dequeue()->getItem()->getCompletionTime();
            } else {
                //arrival event: just print and add to customer queue and
                eventList->peek()->getItem()->message(currTime);
                customerList->insert(createCopy(eventList->peek()->getItem()));
                currTime = eventList->dequeue()->getItem()->getCompletionTime();

                if(eventList->peek() == nullptr) {
                    //get right to the next one if there's nothing happening in the event list after this

                    eventList->insert(createPrep(customerList->dequeue()->getItem(), currTime));
                    //first loop needs to create preparation event
                }
            }
        }


    } else {
        //invalid version
        cout << "Version invalid. Please choose a number from 1 to 3." << endl;
    }

    //print out final remarks for simulation
    cout << "...simulation ended." << endl;
    cout << "- Total number of orders completed: " << totalOrders << endl;
    cout << "- Total revenue: " << revenue << endl;
}

/* ---------------------------------------------------------------------------------------
 *  Parse(string)
 *
 *  PURPOSE: Take a string of text from the file and read its info from token to token. Then it checks what kind of order it is
 *  and creates a FoodOrder object based off of the type (Salad, Stew, Pizza, Burger) and stores it in an event (Arrival event).
 *  PARAMETERS:
 *  string line - line from the input file to parse.
 *
 *  RETURNS: An arrival event with the information filled in (Arrival time, expiry, type of food, etc) to be used in the simulation.
 *
 *  ---------------------------------------------------------------------------------------
 */

Arrival* ParseFile::parse(string line){

    stringstream sst(line);  //stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
    string token;
    int counter = 0;
    int time = 0;
    int expiry = 0;
    string meal = "";
    int numIngredients = 0;

    while(sst >> token)  //reading one token at a time
    {
        if(counter == 0) // time
            time = stoi(token);
        else if(counter == 1) // expiry
            expiry = stoi(token);
        else if(counter == 2) // meal's type
            meal = token;
        else //counting ingredients from here (if counter > 2)
        {
            numIngredients++;
        }
        counter++;
    }

    //code from the example file:

    FoodOrder *newMeal;

    if(meal.compare("Salad") == 0){
        newMeal = new Salad();
    } else if (meal.compare("Burger") == 0){
        newMeal = new Burger();
    } else if (meal.compare("Pizza")== 0) {
        newMeal = new Pizza();
    } else if (meal.compare("Stew")== 0){
        newMeal = new Stew();
    }

    readOrders++;
    Arrival * out = new Arrival(readOrders, newMeal, time, expiry, numIngredients, time);

    return out;

}

/* ---------------------------------------------------------------------------------------
 *  createCopy
 *
 *  PURPOSE: Create a copy of an event to store into the customer queue to keep track of which customer's order is next.
 *  Doesn't really matter what type of event it is, but needs to be a separate Object because the next pointer is being used in the
 *  Event Queue and will be overwritten if used for both Customer Queue and Event Queue.
 *  Creates a completely new object with the same field values as param Event*. This method makes it easier to create a new Event (less typing).
 *  PARAMETERS:
 *  Event * e = Event to copy.
 *
 *  RETURNS: Event* - Copied Event object that is the same as e param.
 *
 *  ---------------------------------------------------------------------------------------
 */

Event* ParseFile::createCopy(Event * e){
    Event *out = new Event(e->getID(), e->getMeal(), e->getArrival(), e->getExpiry(), e->getIngredients(), e->getCompletionTime());
    return out;
}

/* ---------------------------------------------------------------------------------------
 *  createPrep(Event*, int)
 *
 *  PURPOSE: Create a Prepare event using another Event's fields. Easy way to create a new Prepare event with less typing.
 *  Usually used with an Arrival event as Param, because Prepares are created based on the Arrival event.
 *  PARAMETERS:
 *  Event * e - Event to copy fields from
 *  int currTime - current time in simulation
 *
 *  RETURNS: A prepare event based on the fields of e.
 *
 *  ---------------------------------------------------------------------------------------
 */

Prepare* ParseFile::createPrep(Event * e, int currTime) {
    //taking in arrival and current time and creating a prepare event

    Prepare *out = new Prepare(e->getID(), e->getMeal(), e->getArrival(), e->getExpiry(), e->getIngredients(), currTime);

    return out;
}

/* ---------------------------------------------------------------------------------------
 *  createDeparture(Event *, int)
 *
 *  PURPOSE: Create a Departure event (CompleteService Event) based on the Event e passed into it and the current time.
 *  Departure time/completion time is calculated by adding current time to the amount of time Event e would take to prepare completely.
 *  Creates an event for when the prepare event finishes.
 *  PARAMETERS:
 *  Event * e - Event to create CompleteService event for
 *  int currTime - current time in simulation
 *
 *  RETURNS: CompleteService* the Event that marks the time of completion of an action in the simulation based on the Event e param
 *  and the current time in the simulation.
 *
 *  ---------------------------------------------------------------------------------------
 */

CompleteService* ParseFile::createDeparture(Event * e, int currTime) {
    //taking in arrival and current time and creating departure event
    //constructors for each of these classes are different for currTime
    int departure = currTime + e->getIngredients() + e->getMeal()->getTime();

    CompleteService *out = new CompleteService(e->getID(), e->getMeal(), e->getArrival(), e->getExpiry(), e->getIngredients(), departure);

    return out;
}
