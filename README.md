# ActionScheduler

A library for easy scheduling of both one-time and repeating code sequences ("Actions").
Avoids limitations and complications of function pointers, but instead requires user to
define their own subclasses that contain the code they wish to execute.
Includes container class to handle checking Actions and deleting them once completed.

## How to use this library

Many Arduino libraries to handle timing of code execution already exist. However, the vast majority tend to use
function pointers to allow the user to supply the code to execute.  While this is a simpler solution,
it often limits the user to only static void functions with no parameters. This library takes a different approach;
it provides an abstract class (Action) that handles timing, and calls the virtual function `execute()` when that
timer triggers. The user can then make a subclass of Action and provide their own implementation of `execute()`
to be called.

Once this is done, simply create an instance of the class in a sketch, specifying how long (in milliseconds) to
wait before executing, and repeatedly call the `check()` method.
This checks to see if the allotted time has passed; if so, it will call `execute()` and return true. Otherwise,
nothing happens, and `check()` will return false. If it is important for the rest of the program to know when
the Action is executed, this return value must be monitored; otherwise it can be ignored, as further calls to
`check()` will have no effect.

## RepeatingAction

Action is meant to provide a base for classes whose code should only execute once. If the user needs to call
a block of code on regular intervals, they should instead subclass RepeatingAction (itself a subclass of Action).
`RepeatingAction.check()` will always return false, so there is no need to check the value. Once `execute()` is
called, the timer resets so that the same code can be executed again and again after the specified interval.

## Subclass Template

At a minimum, a subclass of Action needs a constructor which calls the Action constructor, and a definition for
the `execute()` function. Omitting either of these will cause errors. The following template shows how such a
subclass should be written.

In MySubclass.h:

	#ifndef MySubclass_h
	#define MySubclass_h
	
	#include <Arduino.h>
	#include <Action.h>
	
	class MySubclass: public Action {
	  public:
	    MySubclass();
	  private:
	    void execute();
	};
	
	#endif

In MySubclass.cpp:

	#include "MySubclass.h"
	
	MySubclass::MySubclass(unsigned long waitTime):Action(waitTime) {
	  //additional constructor code if needed
	}
	
	void MySubclass::execute() {
	  //code to run when waitTime is reached
	}

Additional variables can be defined by the user as needed. To subclass RepeatingAction, simply replace any
instance of "Action" with "RepeatingAction" in the template.
Once this is done, the class can be used in a sketch.

## The Scheduler Class

Since handling a large number of Actions is difficult, expecially if they're generated in an unpredictable way
(due to user or environment input, for example), this library provides a container class for Actions: Scheduler.
This class is essentially a linked list of Actions that can be added to, and will automatically delete Actions
that have run their course. For this to work, however, Scheduler uses pointers to dynamically created objects;
i.e. objects created using the `new` operator. Passing pointers to static objects will cause hard-to-debug
runtime errors, so **don't do it.**

In addition, Scheduler assumes it is the only object with access to its Actions. Attempting to manipulate Actions
already passed to Scheduler could also cause runtime errors, so **don't do that either.** The best practice to
avoid this is to create the object directly inside the function to pass it to the Scheduler. For example:

	Scheduler myScheduler;
	myScheduler.schedule(new MySubclass(1000));
	
This adds a new instance of MySubclass to be executed in 1000 ms (1 second). Note that just like individual
Actions, the user must manually and regularly check the Scheduler:

	void loop() {
	  myScheduler.checkActions();
	}

This checks all Actions that have been scheduled, and deletes those that trigger (except for subclasses of
RepeatingAction, which by definition are supposed to occur more than once).

Once scheduled, Actions cannot be directly cancelled. However, when adding an action to the Scheduler, the
user can specify a keyword (a non-empty string) with the Action. Then, any action with that keyword can be
cancelled, like so:

	myScheduler.schedule(new MySubclass(1000), "someKeyword"); //schedule action for 1 second later
	myScheduler.cancel("someKeyword"); //cancel and delete any action scheduled with the keyword

Lastly, to clear all Actions from the Scheduler:

	myScheduler.clear();

Note that this also deletes any RepeatingAction passed to the scheduler.