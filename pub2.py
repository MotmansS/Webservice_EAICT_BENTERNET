import zmq
import random
import time
import string
from dataclasses import dataclass
# ZeroMQ Context
context = zmq.Context()

PubSock = context.socket(zmq.PUSH)
SubSock = context.socket(zmq.SUB)


SubSock.connect("tcp://benternet.pxl-ea-ict.be:24042")
PubSock.connect("tcp://benternet.pxl-ea-ict.be:24041")
SubSock.setsockopt_string(zmq.SUBSCRIBE, "BlackJackService>Client>")
translatearr = '123456789ABCD'
class Playr:
	def __init__(self, name, score,DealerScore,randomkaart,randomdealerkaart,pcontinue,computerhand,playerhand,bufferhand,tempname,counter):
		self.name= name
		self.score =score
		self.DealerScore=DealerScore
		self.randomkaart= randomkaart 
		self.randomdealerkaart= randomdealerkaart 
		self.pcontinue= pcontinue
		self.computerhand = computerhand
		self.playerhand=playerhand
		self.bufferhand= bufferhand
		self.tempname= tempname
		self.counter = counter;
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

	playerlist.append(Playr('',0,0,0,0,'',"GGGGGGGGG","GGGGGGGGG","GGGGGGGGG","",0))
	for i in range(9):
		for Player in playerlist:
			 	
				Player.name  =  SubSock.recv_string().split('>')[-1]
				print(Player.name)
				
				if Player.name != 'y' and  Player.name  !='n' :
				
				
					#message [prefix][message]
					message = "BlackJackService>Player>{name}".format(name = Player.name)
					print(len(message))
					print(message)
					PubSock.send_string(message)
					print("name sent")
					
					#SubSock.setsockopt_string(zmq.SUBSCRIBE, "BlackJackService>Client>{name}".format(name = Player.name ))
					SubSock.setsockopt_string(zmq.SUBSCRIBE, "BlackJackService>Client")
					print("BlackJackService>Client>{name}".format(name = Player.name ))
					print("we got this far1")
					PubSock.send_string(message)
				
					
					print("we got this far 11")
					Player.pcontinue = SubSock.recv_string()
					Player.tempname =   Player.pcontinue.split('>')[-2]
					print("name:")
					print(Player.tempname)
					if Player.name == Player.tempname:
					
						Player.pcontinue = Player.pcontinue.split('>')[-1]
						if Player.pcontinue == 'New':
							Player.playerhand ="GGGGGGGGG"
							Player.score = 0
							Player.computerhand = "GGGGGGGGG"
							Player.bufferhand = "GGGGGGGGG"
							Player.DealerScore = 0
							Player.counter = 0

						print(Player.pcontinue)
						
						print("we recieved the y or no")
						print(Player.pcontinue)
						if Player.pcontinue == 'y':
							Player.counter = Player.counter +1
							if  Player.counter >=9 :
								Player.counter = 0
							print("we got to The Yes")
							Player.randomkaart = random.randint(0,12)
							Player.randomdealerkaart = random.randint(0,12)
							BuffListp= list(Player.playerhand)
							BuffListp[Player.counter] = translatearr[Player.randomkaart]
							Player.playerhand =  convert(BuffListp)
							message = "BlackJackService>Player>{name}>PlayerHand>{hand}".format(name = Player.name,hand = Player.playerhand)
							PubSock.send_string(message)
							print("we got to Draw A card")
							BuffListc= list(Player.computerhand)
							BuffListc[Player.counter] = translatearr[Player.randomdealerkaart]
							Player.computerhand =  convert(BuffListc)
							message = "BlackJackService>Player>{name}>ComputerHand>{hand}".format(name = Player.name,hand = Player.computerhand)
							print(message)			
							PubSock.send_string(message)					
							print("we got to Play")
						elif Player.pcontinue == 'n':
							if (Player.score < 22 and Player.score > Player.DealerScore )or (Player.score < 22 and Player.DealerScore > 22) or(Player.score > Player.DealerScore):
								message = "BlackJackService>Player>{name}>Score>WIN".format(name = Player.name )
							else:
								message = "BlackJackService>Player>{name}>Score>LOSE".format(name = Player.name )
								#playerlist.remove(Player)
								PubSock.send_string(message)
								score = 0
								DealerScore = 0
								break

