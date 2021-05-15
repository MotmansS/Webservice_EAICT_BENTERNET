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
def convert(s):
  
    # initialization of string to ""
    new = ""
  
    # traverse in the string 
    for x in s:
        new += x 
  
    # return string 
    return new
    	
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
					BuffListp= list(Player.playerhand)
					BuffListp[i] = translatearr[Player.randomkaart]
					Player.playerhand =  convert(BuffListp)
					message = "BlackJackService>Player>{name}>PlayerHand>{hand}".format(name = Player.name,hand = Player.playerhand)
					PubSock.send_string(message)
					print("we got to Draw A card")
					BuffListc= list(Player.computerhand)
					BuffListc[i] = translatearr[Player.randomdealerkaart]
					Player.computerhand =  convert(BuffListc)
					message = "BlackJackService>Player>{name}>ComputerHand>{hand}".format(name = Player.name,hand = Player.computerhand)
					print(message)			
					PubSock.send_string(message)					
					print("we got to Play")
				elif Player.pcontinue == 'n':
					#if (Player.score < 22 and score > DealerScore )or (score < 22 and DealerScore > 22):
					#	message = "BlackJackService>Player>{name}>Score>WIN"
					#else:
					#	message = "BlackJackService>Player>{name}>Score>LOSE"
					del playerlist[Player]
					#PubSock.send_string(message)
					#score = 0
					#DealerScore = 0
					break
				
