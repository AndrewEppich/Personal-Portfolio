import time
import random

class1 = ["Barbarian", 30, 5, 0.2]
class2 = ["Wizard", 20, 8, 0.3]
class3 = ["Monk", 15, 12, 0.3]
npc = ["Warlock", 25, 7, 0.2]

player_name = input("Hello! What is your name ")
print("Welcome to combat, " + player_name) 
time.sleep(2)
print("Hello " + player_name + ", It is time to choose your class. ")
print("class1 is a barbarian who has high health but deals low damage. class2 is a wizard who has less health but deals more damamge. And class3 which is a monk that has low health but deals the highest damage")
player_class = input("Which class will you choose? ")
if player_class == "class1":
    player_class = class1
    print("Your oppenent is a " + npc[0] + "! Your player class is " + class1[0] + " Your starting health is 30 and your oppenents starting health is " + str(npc[1]))
elif player_class == 'class2':
    player_class = class2
    print("Your oppenent is a " + npc[0] + "! Your player class is " + class2[0] + " Your starting health is 20 and your oppenents starting health is " + str(npc[1]))
elif player_class == 'class3':
    player_class = class3
    print("Your oppenent is a " + npc[0] + "! Your player class is " + class3[0] + " Your starting health is 15 and your oppenents starting health is " + str(npc[1]))
time.sleep(2)
print("It is time to start the battle")
time.sleep(2)
while npc[1] > 0 and player_class[1] > 0:
    player_choice = input("Type a for attack or d or dodge ")
    if player_choice == 'a':
        print("You have chosen to attack. Waiting on npc choice... ") 
    elif player_choice == 'd':
        print("You have chosen to dodge. Waiting on npc choice... ")
    else:
        print("This is not an option. Would you like to attack or dodge?")
        player_choice = input("Type a for attack or d for dodge ")
    time.sleep(1)
    if player_choice == 'a' and random.randint(1,20) % 2 ==0:
         print("The npc and the player attack")
         player_class[1] -= npc[2]
         npc[1] -= player_class[2]
         print("Your health is " + str(player_class[1]))
         print("Your opponents health is " + str(npc[1])) 
    elif player_choice == 'a' and random.randint(1,20) % 2 != 0:
        print("The npc dodges and the player attacks")
        npc[1] -= (player_class[2] * player_class[3])
        print("The opponent dodged so you attack did less damage!")
        time.sleep(1)
        print("The opponents health is " + str(npc[1]))
        print("Your health is " + str(player_class[1]))
    elif player_choice == 'd' and random.randint(1,20) % 2 == 0:
        print("The npc attacks and the player dodges")
        player_class[1] -= (npc[2] * npc[3])
        print("You dodged so your opponents attack did less damage!")
        time.sleep(1)
        print("Your health is " + str(player_class[1]))
        print("Your opponents health is " + str(npc[1]))
    elif player_choice == 'd' and random.randint(1,20) % 2 != 0:
        print("The npc dodges and the player dodges")
        time.sleep(1)
        print("The opponents health is " + str(npc[1]))
        print("Your health is " + str(player_class[1])) 
    elif npc[1] <= 0:
        break
    elif player_class[1] <= 0:
        break
if player_class[1] <= 0:
    print("You have been defeated")
elif npc[1] <= 0:
    print("You have defeated your opponent!")