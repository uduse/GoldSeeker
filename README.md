# GoldSeeker
An Interface for CS Club Competition

##About

###Date 
1/29/15 ~ 2/6/15 (~30 hours)

###Author
Uduse
###Contact
wzy950618@gmail.com

###Description
A program made as an interface for a competition of CS Club at UC Davis.
Competitors will write a short algorithm in 2~3 hours, controlling the
charactor to collect as many golds as possible in a randomly generated
cave with limited oxygen.

##Details
###Storyline
You are an enthusiastic gold seeker and you want to make a fortune by collecting golds left in a cave by ancient pirates.

You just found the entrance of the cave, and you know you can't stay in the cave forever to find all golds because oxygen in the cave is limited and you want to get out the cave alive.
Therefore, you decide to develop an efficient way to explore the cave as much as possible and collect as many golds as possible before the cave run out of oxygen.

<br>

###Your Equipment

####Backpack
What you use to store the golds you found.

####Sketch Pad
You are also a skilled artist with perfect space perception.

During your exploration, you will mark all places you visited and all walls you encountered on your Sketch Pad.

You may take a look at your Sketch Pad to remind yourself about the details of the cave.


####Ball of Thread
You learned from the story about Theseus and the Minotaur, so you brought with you a Ball of Thread.

You can place it at your current location, and when you retrieve it, it will bring you back given steps, or all the way back to where you placed it.

Since you're smart enough, you always rewind useless thread to prevent loops whenever you step back to somewhere you have placed thread on.

For example, if you place your thread and then take a path like 0 -> 1 -> 2 -> 3 -> 4 -> 2, you will prevent the loop 2 -> 3 > 4 -> 2  and leave thread only on 0 -> 1 -> 2.

You always take notes for how much thread you used.

In addition, since you're good at math, you always converse the amount of used thread based on oxygen. So retrieving one unit of thread would cost one unit of oxygen.

<br>

###Your Moves

####Look
You look in a certain direction and make a mark on your Sketch Pad if you see a wall.
<br>

	bool lookLeft();
	bool lookRight();
	bool lookUp();
	bool lookDown();

return true when there's no wall in that direction.

<br>

	bool lookAround();

return true if there's no wall in any direction.

<br>

####Move
 
You walk towards a certain direction for one step. 

Since it requires movement, the total oxygen in the cave would decrease by 1 unit.
	
	bool moveLeft();
	bool moveRight();
	bool moveUp();
	bool moveDown();

return false when you can't make that move because there's a wall

<br>

####Marked
You look at your Sketch Pad, and check if a certain place next to you has been visited.

	bool markedLeft();
	bool markedRight();
	bool markedUp();
	bool markedDown();

return true if the place next to you in a certain direction has been visited by you.

<br>

####Breathe
You take a breathe and detect the richness of oxygen in the air with your well-trained lungs.

	int breathe();

return the amount of oxygen available in the cave.

<br>

####Backpack
You open your backpack and see how many golds you have collected. 

	int backpack();

return amount of gold you collected.

<br>

####Sketch Pad
You look at your Sketch Pad closely, with all details in eyes.

	void sketchPad();

print the map you created for the cave

<br>

####Ball of Thread
Place the thread at where you are.
	
	bool placeThread();

return false if the ball of thread is in use.

<br>


The thread brings you all the way back to where you placed it, then you pick up the thread. 

	bool retrieveThread();

return false when the ball is still in your hand

<br>

The thread brings you back certain steps, you won't pick up the thread in this case.

	bool retrieveThread( int steps );

return false when the ball is still in your hand.
	
<br>

Check your notes and see how much thread you have used so far. One unit of thread would take one unit of oxygen to retrieve.

	int threadUsed();

return amount thread used

<br>

####Leave
You leave the cave through the entrance with all your golds in your backpack, alive.
	
	bool leave();

return false when you are not next to the entrance

<br>

###Displays##

#####`&` You

#####`@` Entrance

#####`·` Places you visited

#####`*` Places have your thread on
#####`0` Places you collected a gold

<br>


##Things I learned from this project##
1. **How to generate a random map.** I accomplished this by having a brush with thickness moving randomly on a canvas and making marks on it, and places not marked will be walls (not visitable).
2. **A better understanding of Public v.s Private.** That difference did not really matter for projects I have done before this, since I don't really need to hide things from myself, it's just a better "Style" or it's a "Convention" to hide things as private. However, this time, since I am making this interface for a competition, I really need to limit things competitors can access, otherwise it's really easy to cheat.
3. **A better utilization of tools that help me code faster.** Especially "Extract Method," "Create Method," and "Introduce Viable" functions provided by a Visual Studio extension "Visual Assist," and "Simultaneous edit in more than one location in the editor" by "MultiEditing." They helped me a lot in saving my time from doing repetitive and dirty work, so I was able to finish the first working prototype of the project in 15 hours.
4. **How to get colored output in command window.** Learned how to used "Window.h." to make my output colorful, and this made my testing much easier (things are easier to differentiate).
5. **Better understanding of a list and its iterator.** The Ball of thread was implemented as a linked list, and I learned from hours of debugging "Loop Prevention" mechanism of it.
