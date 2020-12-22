#!/usr/bin/python3
# this implementation automatically decodes num strings to words and feeds answers to the server

import socket
import base64

host = 'jupiter.challenges.picoctf.org'
port = 15130

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    host_ip = socket.gethostbyname(host)
    s.connect((host_ip,port))

    while True:
        data = s.recv(4096)

        if not data:
            break

        answer = ""
        for line in data.decode().split(chr(10)):
            print(line)
            """
            Please give the 01101100 01100001 01101101 01110000 as a word.
            Please give me the  156 165 162 163 145 as a word.
            Please give me the 636f6d7075746572 as a word.
            """
            if line.startswith("Please give") and line.endswith("as a word."):
                line = line.rstrip("as as word.")
                for word in line.split(" "):
                    if len(word)<1:
                        continue

                    num = False

                    try:
                        if not num and len(word)==8:
                            num =  int(word,2)
                    except:
                        pass

                    try:
                        if not num and len(word)==3:
                            num =  int(word,8)
                    except:
                        pass

                    try:
                        if not num and len(answer)<1:
                            answer = base64.b16decode(word, casefold=True).decode('ascii')
                            print("base16: %s" % answer)
                            break
                    except:
                        pass

                    try:
                        if not num:
                            num =  int(word,16)
                    except:
                        pass

                    if num:
                        answer += chr(num)
                        #print("IS A NUM: %s (%d)" % (word, num))
                        #print("ANSWER: %s" % answer)

        # send answer to server
        if len(answer)>0:
            print("SENDING ANSWER: %s" % answer)
            s.sendall((answer + chr(10)).encode())
