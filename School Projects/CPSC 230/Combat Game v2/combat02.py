import time
import random

class1 = ["Barbarian", 30, 5, 0.2, 8]
class2 = ["Wizard", 20, 8, 0.3, 11]
class3 = ["Monk", 15, 12, 0.3, 15]
class4 = ["Cleric", 17, 10, 0.2, 13]
class5 = ["Warlock", 25, 7, 0.2, 10]
class6 = ["Ranger", 16, 10, 0.2, 13]
class7 = ["Sorcerer", 15, 13, 0.1, 16]
npc = ["Warlock", 25, 7, 0.2, 10]
npc2 = ["Paladin", 20, 9, 0.3, 12]
npc3 = ["Druid", 23, 10, 0.2, 13]

classes = [class1, class2, class3, class4, class5, class6, class7]
npcs = [npc, npc2, npc3]

print("Welcome to Combat!")
time.sleep(1)
player_name = input("Please enter your name. ")
print("Welcome " + player_name)
print("Here are the available classes and their stats:")

for charecters in classes:
    print(charecters)
    time.sleep(1)
print("select class1, class2, class3, class4, class5, class6, or class7")

while True:
    player_class = input("Choose your class! ").lower()
    if player_class == 'class1':
        player_class = class1
        print("You chose Barbarian!")
        print("These are your stats:" + str(class1))
        break
    elif player_class == 'class2':
        player_class = class2
        print("You chose Wizard!")
        print("These are your stats:" + str(class2))
        break
    elif player_class == 'class3':
        player_class = class3
        print("You chose Monk!")
        print("These are your stats:" + str(class3))
        break
    elif player_class == 'class4':
        player_class = class4
        print("You chose Cleric!")
        print("These are your stats:" + str(class4))
        break
    elif player_class == 'class5':
        player_class = class5
        print("You chose Warlock!")
        print("These are your stats:" + str(class5))
        break
    elif player_class == 'class6':
        player_class = class6
        print("You chose Ranger!")
        print("These are your stats:" + str(class6))
        break
    elif player_class == "class7":
        player_class = class7
        print("You chose Sorcerer!")
        print("These are your stats" +str(class7))
        break
    else: 
        print("That is not an available class. Please choose again")

time.sleep(1)
print("Now its time to choose an opponent!")
time.sleep(1)

while True:
    random_enemy = input("Enter 'yes' to choose your opponent or 'no' to have it chosen for you ").lower()
    if random_enemy == 'yes' or 'Yes':
        for enemy in npcs:
            print(enemy)
            time.sleep(1)

        while True:
            enemy_select = input("Choose your enemy: easy(npc), medium(npc2), hard(npc3) ").lower()
            if enemy_select == 'easy' or enemy_select == 'npc':
                enemy = npc
                print(f"These are your opponents stats: {npc}")
                break
            elif enemy_select == 'medium' or enemy_select == 'npc2':
                enemy = npc2
                print(f"These are your opponents stats: {npc}")
                break
            elif enemy_select == 'hard' or enemy_select == 'npc3':
                enemy = npc3
                print(f"These are your opponents stats: {npc}")
                break
            else:
                print("That is not an available class. Please choose again")
        break
    elif random_enemy == 'no' or 'No':
        npc = random.choice(npcs)
        print(f"These are your opponents stats: {npc}")
        break
    else:
        print("That is not an available class; Please choose again")

time.sleep(1)
player_class_health = player_class[1]
time.sleep(1)
enemy_health = enemy[1]
time.sleep(1)

enemy_choices = ['attack', 'dodge', 'special attack']
enemy_choice = random.choice(enemy_choices) 

print("Now the npc will roll a die to determine if they will attack, dodge, or use special attack")

def roll_d10(attack):
    roll = random.randint(1, 10)
    rolled = roll + attack
    return rolled

def calculate_player_damage(player_class, player_choice):
    if player_choice == "attack":
        damage = roll_d10(player_class[2])
    elif player_choice == "special attack":
        damage = roll_d10(player_class[4])
    elif player_choice == "dodge":
        damage = 0
    return damage

def calculate_enemy_damage(enemy, enemy_choice):
    if enemy_choice == "attack":
        damage = roll_d10(enemy[2])
    elif enemy_choice == "special attack":
        damage = roll_d10(enemy[4])
    elif enemy_choice == "dodge":
        damage = 0
    return damage


def print_results(player_choice, enemy_choice, player_damage, enemy_damage, player_health, enemy_health):
    if player_damage > 0 and enemy_damage > 0:
        print(f"You used {player_choice} and dealt {player_damage} damage. Your opponent countered your attack with {enemy_choice} and dealt {enemy_damage} damage to you.")
        player_health -= enemy_damage
        enemy_health -= player_damage
        print(f"Your health is {player_health}")
        print(f"Your enemy's health is {enemy_health}") 
    elif player_damage > 0 and enemy_damage == 0:
        print(f"You used {player_choice} which dealt {player_damage} damage. Your opponent dodged and dealt no damage.")
        enemy_health -= player_damage
        print(f"Your health is {player_health}")
        print(f"Your enemy's health is {enemy_health}") 
    elif player_damage == 0 and enemy_damage > 0:
        print(f"You used {player_choice} and your enemy attacked you with {enemy_choice} and dealt {enemy_damage} damage.")
        player_health -= enemy_damage
        print(f"Your health is {player_health}")
        print(f"Your enemy's health is {enemy_health}") 
    else:
        print(f"You used {player_choice} and your enemy used {enemy_choice}, but neither did damage.")
        print(f"Your health is {player_health}")
        print(f"Your enemy's health is {enemy_health}") 


print('Round 1')
time.sleep(2)
print(f"Your health is {player_class_health}")
print(f"Your enemy's health is {enemy_health}")  
time.sleep(1)

while player_class_health > 0 and enemy_health > 0:
    player_choice = input("Attack, Special Attack, or Dodge? ").lower()
    enemy_choice = random.choice(enemy_choices)

    if player_choice.lower() == 'attack' or player_choice.lower() == 'special attack' or player_choice.lower() == 'dodge':
        player_damage = calculate_player_damage(player_class[2], player_choice)
        enemy_damage = calculate_enemy_damage(enemy[2], enemy_choice)

        print_results(player_choice, enemy_choice, player_damage, enemy_damage, player_class_health, enemy_health)

        player_class_health -= enemy_damage
        enemy_health -= player_damage

        if player_class_health <= 0 and enemy_health <= 0:
            print(f"{player_name}, you and your enemy have both been defeated .")
            break
        elif player_class_health <= 0:
            print(f"Your enemy has won, {player_name}!")
            break
        elif enemy_health <= 0:
            print(f"{player_name}, You have defeated your enemy!")
            break
    else:
        print("This choice is not a valid selection. Please choose again")
