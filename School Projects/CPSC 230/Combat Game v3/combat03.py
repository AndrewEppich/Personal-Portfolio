import time
import random

roll = random.randint(1, 20)

barbarian = dict(name = 'Barbarian',health = 50, attack = roll, spAttack = (roll + 3), cooldown = 4, coolcount = 4, dodge = 0, AC = 5)
cleric = dict(name = 'Cleric' ,health = 30, attack = roll, spAttack = (roll + 3), cooldown = 3, coolcount = 3, dodge = 0, AC = 3)
wizard = dict(name = 'Wizard' , health = 32, attack = roll, spAttack = (roll + 3), cooldown = 3, coolcount = 3, dodge = 0, AC = 3)
monk = dict(name = 'Monk' ,health = 27, attack = roll, spAttack = (roll + 3), cooldown = 2, coolcount = 2, dodge = 0, AC = 2)
warlock = dict(name = 'Warlock' ,health = 40, attack = roll, spAttack = (roll + 3), cooldown = 4, coolcount = 4, dodge = 0, AC = 4)
ranger = dict(name = 'Ranger' ,health = 28, attack = roll, spAttack = (roll + 3), cooldown = 3, coolcount = 3, dodge = 0, AC = 2)
sorcerer = dict(name = 'Sorcerer' ,health = 30, attack = roll, spAttack = (roll + 3), cooldown = 3, coolcount = 3, dodge = 0, AC = 3)
easyenemy = dict(difficulty = 'Easy', name = 'Super Sorcerer' ,health = 35, attack = roll, spAttack = (roll + 3), cooldown = 4, coolcount = 4, dodge = 0, AC = 3)
mediumenemy = dict(difficulty = 'Medium', name = 'Super Warlock' ,health = 47, attack = roll, spAttack = (roll + 3), cooldown = 3, coolcount = 3, dodge = 0, AC = 4)
hardenemy = dict(difficulty = 'Hard' ,name = 'Super Barbarian' ,health = 60, attack = roll, spAttack = (roll + 3), cooldown = 3, coolcount = 3, dodge = 0, AC = 5)

Characters = [barbarian, cleric, wizard, monk, warlock, ranger, sorcerer]
enemies = [easyenemy, mediumenemy, hardenemy]

print("Welcome to combat")
time.sleep(1)
file_name = input("Before we begin, Enter a file name for the transcript: ")
transcript_file = open(file_name, "w")
player_name = input("What is your name? ")
print(f"Hello {player_name} It is time to slect your character")
print("Here are the available classes and their stats!")

for character in Characters:
    print(character)
    time.sleep(1)

while True:
    player_class = input("Choose your class ")
    if player_class.lower() == 'barbarian':
        player_class = barbarian
        print("You chose Barbarian!")
        print("Here are your stats" + str(barbarian))
        break
    elif player_class.lower() == 'cleric':
        player_class = cleric
        print("You chose Cleric!")
        print("Here are your stats" + str(cleric))
        break
    elif player_class.lower() == 'wizard':
        player_class = wizard
        print("You chose Wizard")
        print("Here are you stats" + str(wizard))
        break
    elif player_class.lower() == 'monk':
        player_class = monk
        print("You chose Monk")
        print("Here are your stats" + str(monk))
        break
    elif player_class.lower() == 'warlock':
        player_class = warlock
        print("You chose Warlock")
        print("Here are your stats" + str(warlock))
        break
    elif player_class.lower() == 'ranger':
        player_class = ranger
        print("You chose Ranger")
        print("Here are your stats" + str(ranger))
        break
    elif player_class.lower() == 'sorcerer':
        player_class = sorcerer
        print("Your chose sorcerer")
        print("Here are your stats" + str(sorcerer))
        break
    else:
        print("This is not a valid class. Please choose again")


time.sleep(1)
print("Now it is time to choose your opponent")
time.sleep(1)

while True:
    random_enemy = input("Type y to choose your opponent or n for it to be randomly chosen ")
    if random_enemy == 'y' or random_enemy == 'Y':
        for enemy in enemies:
            print(enemy)
            time.sleep(1)

        while True:
            enemy_select = input("Choose your enemy: easy, medium, or hard ")
            if enemy_select == 'easy' or enemy_select == 'Easy':
                index = enemies.index(easyenemy)
                enemy_select = enemies[index]
                print("You chose Easy")
                print("Here are your enemy's stats" + str(enemy_select))
                break
            elif enemy_select == 'medium' or enemy_select == 'Medium':
                index = enemies.index(mediumenemy)
                enemy_select = enemies[index]
                print("You chose Medium")
                print("Here are your enemy's stats" + str(enemy_select))
                break
            elif enemy_select == 'hard' or enemy_select == 'Hard':
                index = enemies.index(hardenemy)
                enemy_select = enemies[index]
                print("You chose Hard")
                print("Here are your enemy's stats" + str(enemy_select))
                break
            else:
                print("Invalid choice. Please choose again")
        break
    elif random_enemy == 'n' or random_enemy == 'N':
        enemy_select = enemies[random.choice(list(enemies.keys()))]
        print("These are your enemy's stats" + str(enemy_select))
        break
    else:
        print("Invalid choice. Please choose again")

time.sleep(1)
player_health = player_class['health']
time.sleep(1)
enemy_health = player_class['health']
time.sleep(1)

enemy_choices = ['attack', 'dodge', 'spAttack']
enemy_choice = random.choice(enemy_choices)

print("Now the enemy will roll the dice to determine their move")

roll = random.randint(1, 30)

def roll_d30(attack_type):
    if attack_type == 'attack':
        attack = int(player_class['attack'])
    elif attack_type == 'spAttack':
        attack = int(player_class['spAttack'])
    else:
        attack = int(player_class['dodge'])
    roll = random.randint(1, 30)
    rolled = roll + attack
    return rolled



def calculate_damage(attacker, attack_type):
    base_damage = roll_d30(attack_type)
    if attacker == player_class:
        attack_modifier = calculate_attack_modifier()
        dodge_modifier = calculate_dodge_modifier(enemy)
    else:
        attack_modifier = calculate_attack_modifier(enemy)
        dodge_modifier = calculate_dodge_modifier()
    if base_damage + attack_modifier > dodge_modifier:
        return base_damage + attack_modifier - dodge_modifier
    else:
        return 0

def calculate_attack_modifier(entity=None):
    if entity is None:
        return 0
    elif entity['dodge']:
        return -5
    else:
        return entity['AC'] - 10

def calculate_dodge_modifier(entity=None):
    if entity is None:
        return 0
    elif entity['attack']:
        return -5
    else:
        return entity['dexterity_modifier'] + entity['AC'] - 10



def print_results(player_action, enemy_action, player_damage, enemy_damage, player_health, enemy_health):
    if player_damage > 0 and enemy_damage > 0:
        print(f"You attacked with {player_action} dealing {player_damage} damage. Your opponent used {enemy_action} dealing {enemy_damage} damage.")
        transcript_line = f'Player attacked with {player_action} dealing {player_damage} damage. Opponent countered with {enemy_action} and dealt {enemy_damage} damage.'
        transcript_file.write(transcript_line + "\n")
        player_health -= enemy_damage
        enemy_health -= player_damage
        print(f'Your health is {player_health}')
        print(f'Your enemys health is {enemy_health}') 
    elif player_damage > 0 and enemy_damage == 0:
        print(f"You attacked with {player_action} dealing {player_damage} damage. Your opponent defended and did 0 damage.")
        transcript_line = f'Player attacked with {player_action} dealing {player_damage} damage. Opponent defended and did 0 damage.'
        transcript_file.write(transcript_line + "\n")
        enemy_health -= player_damage
        print(f'Your health is {player_health}')
        print(f'Your enemys health is {enemy_health}') 
    elif player_damage == 0 and enemy_damage > 0:
        print(f"You tried to {player_action}. Your opponent attacked with {enemy_action} dealing {enemy_damage} damage.")
        transcript_line = f'Player tried to {player_action} but the opponent attacked with {enemy_action} and did {enemy_damage} damage.'
        transcript_file.write(transcript_line + "\n")
        player_health -= enemy_damage
        print(f'Your health is {player_health}')
        print(f'Your enemys health is {enemy_health}') 
    else:
        print(f"You both {player_action} and {enemy_action}, and neither dealth damage.")
        transcript_line = f'Player tried {player_action} and the opponent tried {enemy_action}, but no damage was dealt.'
        transcript_file.write(transcript_line + "\n")
        print(f'Your health is {player_health}')
        print(f'Your enemys health is {enemy_health}') 





print('Begin')
time.sleep(1)
print(f'Your health is {player_health}')
print(f'Your opponents health is {enemy_health}')  
time.sleep(1)


while player_health > 0 and enemy_health > 0:
    player_choice = input('attack, spAttack, or dodge? ')
    enemy_choice = random.choice(enemy_choices)

    if player_choice == 'attack' or player_choice == 'spAttack' or player_choice == 'dodge':
        player_damage = calculate_damage(player_class, player_choice)
        enemy_damage = calculate_damage(enemy, enemy_choice)

        print_results(player_choice, enemy_choice, player_damage, enemy_damage, player_health, enemy_health)

        player_health -= enemy_damage
        enemy_health -= player_damage

        if player_health <= 0 and enemy_health <= 0:
            print(f"It's a draw, {player_name} you have both been deafeated.")
            transcript_line = f'DRAW'
            transcript_file.write(transcript_line + "\n")
            break
        elif player_health <= 0:
            print(f"You have been defeated by your opponent, {player_name}!")
            transcript_line = f'NPC WINS'
            transcript_file.write(transcript_line + "\n")
            break
        elif enemy_health <= 0:
            print(f"{player_name} You have defeated your opponent!")
            transcript_line = f'{player_name.upper()}, WINS'
            transcript_file.write(transcript_line + "\n")
            break
    else:
        print('Invalid selection')

transcript_file.close()
