#!/usr/bin/python
# -*- encoding:utf-8 -*-

import sys
import socket
import time
import os
import random
import getopt

class IA():

	def __init__(self, name, connexion_server):

		self.TargetPosX = 0
		self.TargetPosY = 0
		self.team = name
		self.level = 1
		self.state =
		self.socketfd = connexion_server

		#linemate, deraumere, sibur, mendiane, phiras, tystame, joueur

		self.need_lvl = []

		# grow to level2
		level2 = [1,0,0,0,0,0,1]
		self.need_lvl.append(level2)

		# grow to level3
		level3 = [1,1,1,0,0,0,2]
		self.need_lvl.append(level3)

		# grow to level4
		level4 = [2,0,1,0,2,0,2]
		self.need_lvl.append(level4)

		# grow to level5
		level5 = [1,1,2,0,1,0,4]
		self.need_lvl.append(level5)

		# grow to level6
		level6 = [1,2,1,3,0,0,4]
		self.need_lvl.append(level6)

		# grow to level7
		level7 = [1,2,3,0,1,0,6]
		self.need_lvl.append(level7)

		# grow to level8
		level8 = [2,2,2,2,2,1,6]
		self.need_lvl.append(level8)

		self.socketfd.send(team)

	def gauche(self):
		return "gauche"

	def droite(self):
		return "droite"

	def avance(self):
		return "avance"

	def prend(self):
		print "prend"
		return "prend"

	def pose(self):
		print "pose"
		return "pose"

	def voir(self):
		return "voir"

	def inventaire(self):
		return "inventaire"

	def brodcast(self):
		print "brodcast"
		return "brodcast"

	def incantation(self):
		print "incantation"
		return "incantation"

	def methode(self, option):
		options = {
			"gauche" : self.gauche,
			"droite" : self.droite,
			"avance" : self.avance,
			"prend" : self.prend,
			"pose" : self.pose,
			"voir" : self.voir,
			"inventaire" : self.inventaire,
			"brodcast" : self.brodcast,
			"incantation" : self.incantation
		}

		if option in options.keys():
			options[option]()
		else:
			print "Invalid option."

	def getCommand(self):
		#get commande
		command = ""

		return command

	def run(self):
		msg_recv = self.socketfd.recv(1024)
		while msg_recv != "mort":
			msg_send = self.getCommand()
			self.socketfd.send(self.methode(msg_send))
			msg_recv = self.socketfd.recv(1024)
			time.sleep(3)

def main(args):

	team = ""
	port = 2000
	ip = "localhost"
	check = 0

	if len(args) >= 2 and len(args) <= 6:
		try:
			opts, args = getopt.getopt(args, "t:h:p:", ["team=","host=","port="])
		except getopt.GetoptError as err:
			print "USAGE : ./zappy-ia -t team [-h host=localhost] [-p port=2000]"
			sys.exit(2)

		for elem, a in opts:
			if elem in ("-h", "--host"):
				ip = a
			elif elem in ("-p", "--port"):
				try:
					port = int(a)
				except:
					print "Port must be an int."
					sys.exit(2);
			elif elem in ("-t", "--team"):
				team = a
				check += 1

		if check != 1:
			print "No team name"
			print "USAGE : ./zappy-ia -t team [-h host=localhost] [-p port=2000]"
			sys.exit(2);

		try:
			connexion_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			connexion_server.connect((ip, port))
		except  socket.error as e:
			print "ERROR in open socket \n{}".format(e)
			sys.exit(2)

		ia = IA(team, connexion_server)
		ia.run()

		try:
			connexion_server.close()
		except socket.error as e:
			print "ERROR in close socket \n{}".fomat(e)
			sys.exit(2)
	else:
		print "USAGE : ./zappy-ia -t TEAM [-h HOST=localhost] [-p PORT=2000]"


if __name__ == "__main__":
	main(sys.argv[1:])

