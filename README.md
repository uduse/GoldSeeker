# GoldSeeker
An Interface for CS Club Competition


##About##
###Date### 
1/29/15 ~ 2/6/15 (~30 hours)
###Author###
Uduse
###Contact###
wzy950618@gmail.com

###Description###
A program made as an interface for a competition of CS Club at UC Davis.
Competitors will write a short algorithm in 2~3 hours, controlling the
charactor to collect as many golds as possible in a randomly generated
cave with limited oxygen.

##Details##
###Storyline###
You are an enthuastic gold seeker and you want to make a fortune by collecting golds left in a cave by ancient pirates.

You just found the entrance of the cave, and you know you can't stay in the cave forever to find all golds because oxygen in the cave is limited and you want to get out the cave alive.
Therefore, you decide to develop an effecient way to explore the cave as much as possible and collect as many golds as possible before the cave run out of oxygen.

###Your Moves###
```cpp  
    // You look in a certain direction.
	// return true when no wall
	bool lookLeft();
	bool lookRight();
	bool lookUp();
	bool lookDown();

	// You gaze in four directions.
	//
	// return true if anyone of the directions is a wall
	bool lookAround();


	// You walk towards a certain direction for one step.
	// Since it requires movement, the total oxygen in
	// the cave would decrease by 1.
	//
	// return false when you can't make that move because
	// there's a wall
	bool moveLeft();
	bool moveRight();
	bool moveUp();
	bool moveDown();


	// You look at your Sketch Pad, and check if a certain place
	// next to you has been visited.
	//
	// return true if visitied
	bool markedLeft();
	bool markedRight();
	bool markedUp();
	bool markedDown();

	// You leave the cave through the entrance
	// with all your golds in your backpack, alive.
	//
	// return false when you are not next to the entrance
	bool leave();


	// You take a breathe and detect the richness of
	// oxygen in the air with your well-trainted lungs.
	//
	// return amount of oxygen available in the cave
	int breathe();

	// You open your backpack and check the amount of
	// gold in that.
	//
	// retunr gold you collected.
	int backpack();


	// You are a skilled artist with perfect
	// space perception. During your exploration,
	// you mark all places you have been and
	// all walls you have noticed on your Sketch Pad.
	//
	// You look at your sketchPad closely,
	// with all details in eyes.
	// print the map you created for the cave
	void sketchPad();

	// You check your sketch pad and find out what
	// places you have been.
	//
	// return true if the place next to you in a
	// certain direction has been visited by you.
	bool markedLeft();
	bool markedRight();
	bool markedUp();
	bool markedDown();


	// You learned from the story about Theseus
	// and the Minotaur, so you brought with you
	// a Ball of Thread.
	//
	// You can place it at your current location, and
	// when you retrieve it, it will bring you back given
	// steps, or all the way back to where you placed it.
	//
	// Since you're smart enough, you always rewind
	// useless threads to prevent loops whenever you
	// step back to somewhere you have placed thread on.
	//
	// return false when placing a ball that has been used
	bool placeThread();

	// The thread brings you all the way back to where
	// you placed it, then you pick up the thread.
	// return false when the ball is still in your hand
	bool retrieveThread();

	// The thread brings you back certain steps, you won't
	// pick up the thread in this case.
	// return false when the ball is still in your hand
	bool retrieveThread( int steps );

	// You check your notes and see how much thread you
	// have used.
	//
	// Since you're good at math and you converse the amount
	// of threads used based on oxyen.
	//
	// So retrieving one unit of thread would cost
	// one unit of oxygen.
	//
	// return amount threads used
	int threadUsed();
```

So retrieving one unit of thread would cost one unit of oxygen. return amount threads used
```cpp
	int threadUsed();
```
##Things I learned from this project##
