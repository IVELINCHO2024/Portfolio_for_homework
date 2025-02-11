import random

class Player:
    def __init__(self, name, hp):
        self.name = name
        self.hp = hp

    def heal(self):
        healing = random.randint(1, 4)
        self.hp += healing
        print(f'Player gained {healing} hp')
    
    def deal_damage(self):
        dealt_damage = random.randint(2, 5)
        chance = random.randint(1,5)
        if chance == 1:
            print('The enemy blocked your attack')
            dealt_damage = 0
        else:
            print(f'Player {self.name} dealt {dealt_damage} damage')
        return dealt_damage

    def take_damage(self, damage):
        self.hp -= damage
        print(f'Player {self.name} took {damage} damage') 
    
    
player1 = Player('1', 20)
player2 = Player('2', 20)


while player2.hp > 0 and player1.hp > 0:
    print("Player1's turn")
    print('Choose what to do: ')
    print('1 - Heal')
    print('2 - Deal damage')
    choice_1 = int(input())
    if choice_1 == 2:
        damage_1 = player1.deal_damage()
        player2.take_damage(damage_1)
    
    if choice_1 == 1:
        player1.heal()

    print(f'Player1 hp = {player1.hp}')
    print(f'Player2 hp = {player2.hp} \n')

    print("Player2's turn")
    print('Choose what to do:')
    print('1 - Heal')
    print('2 - Deal damage')
    choice_2 = int(input())

    if choice_2 == 1:
        player2.heal()

    if choice_2 == 2:
        player2.deal_damage()
        damage_2 = player2.deal_damage()
        player1.take_damage(damage_2)

    print(f'Player1 hp = {player1.hp}')
    print(f'Player2 hp = {player2.hp} \n')
    
