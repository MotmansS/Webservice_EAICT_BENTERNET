import zmq
import random
import time
import string
from dataclasses import dataclass
# ZeroMQ Context
context = zmq.Context()

PubSock = context.socket(zmq.PUSH)
SubSock = context.socket(zmq.SUB)


SubSock.connect("tcp://benternet.backup.pxl-ea-ict.be:24042")
PubSock.connect("tcp://benternet.backup.pxl-ea-ict.be:24041")
SubSock.setsockopt_string(zmq.SUBSCRIBE, "BlackJackService>Client>")
translatearr = '123456789ABCD'
class Playr:
	def __init__(self, name, score,DealerScore,randomkaart,randomdealerkaart,pcontinue,computerhand,playerhand,bufferhand):
		self.name= name
		self.score =score
		self.DealerScore=DealerScore
		self.randomkaart= randomkaart 
		self.randomdealerkaart= randomdealerkaart 
		self.pcontinue= pcontinue
		self.computerhand = computerhand
		self.playerhand=playerhand
		self.bufferhand= bufferhand
		
playerlist = []
while True:
	print("we tried so hard")
	
	
	playerlist.append(Playr('',0,0,0,0,'',"GGGGGGGGG","GGGGGGGGG","GGGGGGGGG"))

	for Player in playerlist: 
		Player.name  =  SubSock.recv_string().split('>')[-1]
		print(Player.name )
		
		if Player.name != 'y' and  Player.name  !='n' :
			#message [prefix][message]
			message = "BlackJackService>Player>{name}".format(name = Player.name)
			
			print(len(message))
			print(message)
			PubSock.send_string(message)
			print("name sent")
			
			SubSock.setsockopt_string(zmq.SUBSCRIBE, "BlackJackService>Client>{name}".format(name = Player.name ))
			print("BlackJackService>Client>{name}".format(name = Player.name ))
			print("we got this far1")
			PubSock.send_string(message)
			for i in range(9):
				print("we got this far 11")
					
				Player.pcontinue = SubSock.recv_string().split('>')[-1]
				print(Player.pcontinue)
				
				print("we recieved the y or no")
				print(Player.pcontinue)
				if Player.pcontinue == 'y':
					print("we got to The Yes")
					Player.randomkaart = random.randint(0,12)
					Player.randomdealerkaart = random.randint(0,12)
					#message = " BlackJackService>Player>{name}>DrawnCard>{card}".format(name = Player.name, card =Player.randomkaart )
					#PubSock.send_string(message)
					#if Player.randomkaart == 10:
					#	message = " BlackJackService>Player>{name}>DrawnCard>A".format(name = Player.name)
					#	Player.playerhand += 'A'
					#if Player.randomkaart == 11:
					#	message = " BlackJackService>Player>{name}>DrawnCard>B".format(name = Player.name)
					#	Player.playerhand += 'B'
					#if Player.randomkaart == 12:
					#	message = " BlackJackService>Player>{name}>DrawnCard>C".format(name = Player.name)
					#	Player.playerhand += 'C'
					#if Player.randomkaart == 13:
					#	message = " BlackJackService>Player>{name}>DrawnCard>D".format(name = Player.name)
					#	Player.playerhand += 'D'
					#if Player.randomkaart > 9:
					#	Player.randomkaart = 10; 
					#Player.playerhand += str(Player.randomkaart)
					#Player.score += Player.randomkaart
					#print(Player.playerhand)
					Player.playerhand[i] = translatearr[Player.randomkaart]
					#message = " BlackJackService>Player>{name}>PlayerHand>{hand}".format(name = Player.name,hand = Player.playerhand[:i+1]+Player.bufferhand[i+1:10])
					message = "BlackJackService>Player>{name}>PlayerHand>{hand}".format(name = Player.name,hand = Player.playerhand)
					PubSock.send_string(message)
					#message = " BlackJackService>Player>{name}>Score>{score}".format(score = Player.score)
					#PubSock.send_string(message)
					print("we got to Draw A card")
					#if Player.DealerScore <= 16 :
					#	if Player.randomdealerkaart == 10:
					#		message = " BlackJackService>Player>{name}>DrawnCard>A".format(name = Player.name)
					#		Player.computerhand += 'A'
					#	if Player.randomdealerkaart == 11:
					#		message = " BlackJackService>Player>{name}>DrawnCard>B".format(name = Player.name)
					#		Player.computerhand += 'B'
					#	if Player.randomdealerkaart == 12:
					#		message = " BlackJackService>Player>{name}>DrawnCard>C".format(name = Player.name)
					#		Player.computerhand +='C'
					#	if Player.randomdealerkaart == 13:
					#		message = " BlackJackService>Player>{name}>DrawnCard>D".format(name = Player.name)
					#		Player.computerhand +='D'
					#	if Player.randomdealerkaart > 9:
					#		Player.randomdealerkaart = 10; 
					#	Player.computerhand += str(Player.randomdealerkaart)
					#	Player.score += Player.randomkaart
					print(Player.computerhand)
					#	message = " BlackJackService>Player>{name}>ComputerHand>{hand}".format(name = Player.name, hand = Player.computerhand[:i]+Player.bufferhand[i:9])
					message = "BlackJackService>Player>{name}>ComputerHand>{hand}".format()
						
					PubSock.send_string(message)					
						
						#message = "BlackJackService>{name}>Dealer>DrawnCard>{card}".format(name = Player.name ,card =Player.randomdealerkaart)
						#PubSock.send_string(message)
						#DealerScore += randomdealerkaart
						#message = "BlackJackService>{name}>DealerScore>{score}".format(score = Player.DealerScore)
						#PubSock.send_string(message)
					print("we got to Play")
				elif Player.pcontinue == 'n':
					if (score < 22 and score > DealerScore )or (score < 22 and DealerScore > 22):
						message = "BlackJackService>Player>{name}>Score>WIN"
					else:
						message = "BlackJackService>Player>{name}>Score>LOSE"
					PubSock.send_string(message)
					score = 0
					DealerScore = 0
					break
				
