## Quest Manager

# What is a Quest?
The quests are activities/objectives/actions that the player has to do either alone or cooperatively, to obtain something, either material (objects) or intangible (Continue in the game or experience to level up).

# Type of Quest
* Kill quests: these quests are characterized by the fact that you have to kill enemies or things to complete them, it could be killing enemies, animals or structures, it depends on the game.
* Collect quest: These quests are characterized by the fact that they are collection missions. Normally these quests ask you to collect plants, or objects, but at the same time  usualy can be related to the Quill Quest since you may have to collect animal skin or meat.
* Protection Quest: these questsv are characterized by the fact that you have to protect someone, having to overcome the missions without a character dying.
* Combo Quest: these quests are characterized by the fact that you have to press certain keys in a certain order and time (making a combo), The Quick time events could be classified as combo quests, because if you fail, you can lose. 
* Mixed Quest: These are quests that have one or more types of missions already mentioned above.

![Different Quests Types](https://github.com/rayolop20/Quest_Manager/blob/main/Page_images/Quest_images.png)

The missions, at the same time, can be of different types:
* Main Quest: these Quests are necessary to continue in history and are obligatory.
* Secondary Quest: They are optional Quest, they come out as you complete the main Quest, they are not necessary to continue with the story nor are they obligatory.
* Chained Quest: They are Quest linked to the Quests, that is, once you complete one, they will instantly give you the next one, you will not have to go look for it.
* Events Quest: These are Quest that are active for a limited time, they can be daily, weekly, monthly or specific events for a special occasion.

![Different Quests](https://github.com/rayolop20/Quest_Manager/blob/main/Page_images/Quest_types.png)

# Code
First of all, we must first create the Quests.h module, the module contains the loading and saving of the quests as well as a class, with the quests that you are going to use. this module will be the parent of the other search modules, since the search modules will be derived from it.

![Code1](https://github.com/rayolop20/Quest_Manager/blob/main/Page_images/Code1.png)

Then we are going to create Quest_manager.h and Quest_manager.cpp, these modules will create the entities in the scene and organize them in the game. This module will have the functions to create or destroy the entities in the scenes.

In the first place, we are going to create the quests, in the CreateQuest function, it is important that in this function, we must call the quest Start, since this way the program enters this Quest.cpp function (first we need the quest modules created ).

The Quest_manager will contain the collisions and the mission states, since they will then be used in the Oncolision, which is used in these modules, and then they will be called in the Quest module.

![Code2](https://github.com/rayolop20/Quest_Manager/blob/main/Page_images/Code2.png)
![Code3](https://github.com/rayolop20/Quest_Manager/blob/main/Page_images/Code3.png)

* collisions: collisions are important for the missions, since they will be used as a sensor, and will be used for the player to interact with them.
The collisions are used in the oncolision of Quest_manager, where we will define how the missions will work, in my case I have made them activate with the bools and then the player does TP to indicate that the mission is complete

![Code4](https://github.com/rayolop20/Quest_Manager/blob/main/Page_images/Code4.png)

In the mission module, we are going to initialize the collisions in the Start and then in the update we are going to define what the mission will do, if it ends here, if the player dies...

![Code5](https://github.com/rayolop20/Quest_Manager/blob/main/Page_images/Code5.png)

