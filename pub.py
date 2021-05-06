import zmq
import random
from dataclasses import dataclass
# ZeroMQ Context
context = zmq.Context()

PubSock = context.socket(zmq.PUB)
SubSock = context.socket(zmq.SUB)


SubSock.connect("tcp://benternet.backup.pxl-ea-ict.be:24041")
SubSock.setsockopt_string(zmq.SUBSCRIBE, "BlackJackService>Client>")

PubSock = context.socket(zmq.PUB)
PubSock.connect("tcp://benternet.backup.pxl-ea-ict.be:24042")

@dataclass
class Player:
	name: ''
	score : 0
	DealerScore: 0
	randomkaart: 0 
	randomdealerkaart: 0 
	pcontinue: ''
	computerhand : 'GGGGGGGGGGG'
	playerhand: 'GGGGGGGGGGG'
	
playerlist = []
while True:
	print("we tried so hard")
	
	Player('',0,0,0,0,'','GGGGGGGGGGG','GGGGGGGGGGG')
	playerlist.append(Player)

	for players in playerlist: 
		players.pcontinue =  SubSock.recv()
		print(Players.pcontinue)
		if players.pcontinue != 'y' and  players.pcontinue  !='n' :
			#message [prefix][message]
			message = "BlackJackService>Player>{name}".format(name = players.pcontinue )
			PubSock.send(message)
			player.name = players.pcontinue
			print("we got this far1")
			for i in range(9):

				players.pcontinue = SubSock.recv()
				if players.pcontinue == 'y':
					print("we got to The Yes")
					players.randomkaart = random.randint(1,13)
					players.randomdealerkaart = random.randint(1,13)
					message = " BlackJackService>Player>{name}>DrawnCard>{card}".format(name = players.name, card =players.randomkaart )
					PubSock.send(message)
					if players.randomkaart == 10:
						message = " BlackJackService>Player>{name}>DrawnCard>A".format(name = players.name)
						players.playerhand[i] == A
					if players.randomkaart == 11:
						message = " BlackJackService>Player>{name}>DrawnCard>B".format(name = players.name)
						players.playerhand[i] == B
					if players.randomkaart == 12:
						message = " BlackJackService>Player>{name}>DrawnCard>C".format(name = players.name)
						players.playerhand[i] == C
					if players.randomkaart == 13:
						message = " BlackJackService>Player>{name}>DrawnCard>D".format(name = players.name)
						players.playerhand[i] == D
					if players.randomkaart > 9:
						players.randomkaart = 10; 
					players.playerhand[i] == players.randomkaart
					players.score += randomkaart
					message = " BlackJackService>Player>{name}>PlayerHand>{hand}".format(hand = players.playerhand)
					PubSock.send(message)
					message = " BlackJackService>Player>{name}>Score>{score}".format(score = players.score)
					PubSock.send(message)
					print("we got to Draw A card")
					if DealerScore <= 16 :
						if players.randomdealerkaart == 10:
							message = " BlackJackService>Player>{name}>DrawnCard>A".format(name = players.name)
							players.randomdealerkaart[i] == A
						if players.randomdealerkaart == 11:
							message = " BlackJackService>Player>{name}>DrawnCard>B".format(name = players.name)
							players.computerhand[i] == B
						if players.randomdealerkaart == 12:
							message = " BlackJackService>Player>{name}>DrawnCard>C".format(name = players.name)
							players.computerhand[i] == C
						if players.randomdealerkaart == 13:
							message = " BlackJackService>Player>{name}>DrawnCard>D".format(name = players.name)
							players.computerhand[i] == D
						if players.randomdealerkaart > 9:
							players.randomdealerkaart = 10; 
						players.computerhand[i] == players.randomdealerkaart
						score += randomkaart
						message = " BlackJackService>Player>{name}>ComputerHand>{hand}".format(hand = players.computerhand)
						PubSock.send(message)					
						message = "BlackJackService>{name}>Dealer>DrawnCard>{card}".format(name = players.name ,card =players.randomdealerkaart)
						PubSock.send(message)
						DealerScore += randomdealerkaart
						message = "BlackJackService>{name}>DealerScore>{score}".format(score = players.DealerScore)
						PubSock.send(message)
						print("we got to Play")
				elif players.pcontinue == 'n':
					if (score < 22 and score > DealerScore )or (score < 22 and DealerScore > 22):
						message = " BlackJackService>Player>{name}>Score>WIN"
					else:
						message = " BlackJackService>Player>{name}>Score>LOSE"
				PubSock.send(message)
				score = 0
				DealerScore = 0
				break
				
