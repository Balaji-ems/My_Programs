""" import time and os module """
import time
import os

def log_creator():

    SSH_IP = '192.168.40.252'

    MEM_LIMIT = -1
    SSH_TEXT = "SSHPASS='Qube!123' sshpass -e ssh root@"
    LINE_BREAK = "'\n----------------------------------------------------------------\n'"

    FILE_NAME = time.strftime("%d-%m-%Y-%H:%M.txt")
    FILE_OP = open(FILE_NAME, "w+")
    FILE_OP.write(SSH_IP + '\n')
    TIME = "Date : " + time.strftime("%d-%m-%Y") + "  Time : " \
            + time.strftime("%H:%M:%S") + '\n\nUptime\n\n'
    FILE_OP.write(TIME)
    FILE_OP.close()

    MY_CMD = SSH_TEXT + SSH_IP + " uptime >> " + FILE_NAME
    os.system(MY_CMD)

    MY_CMD = "echo '\nps\n' >> " + FILE_NAME
    os.system(MY_CMD)

    MY_CMD = SSH_TEXT + SSH_IP + " ps >> " + FILE_NAME
    os.system(MY_CMD)

    MY_CMD = "echo " + LINE_BREAK + "'Mem info\n' >> " + FILE_NAME
    os.system(MY_CMD)

    MY_CMD = SSH_TEXT + SSH_IP + " cat /proc/meminfo >> " + FILE_NAME
    os.system(MY_CMD)

    MY_CMD = "echo " + LINE_BREAK + "'Stat\n' >>" + FILE_NAME
    os.system(MY_CMD)

    MY_CMD = SSH_TEXT + SSH_IP + " cat /proc/stat >> " + FILE_NAME
    os.system(MY_CMD)

    MY_CMD = "echo " + LINE_BREAK + "'vmstat\n' >>" + FILE_NAME
    os.system(MY_CMD)

    MY_CMD = SSH_TEXT + SSH_IP + " cat /proc/vmstat >> " + FILE_NAME
    os.system(MY_CMD)

    MY_CMD = "echo " + LINE_BREAK + "'top\n' >>" + FILE_NAME
    os.system(MY_CMD)

    MY_CMD = SSH_TEXT + SSH_IP + " top -n1 >> " + FILE_NAME
    os.system(MY_CMD)

    MY_CMD = SSH_TEXT + SSH_IP +" top -n1 > log.txt"
    os.system(MY_CMD)

    LINES = open("log.txt", "r+").readlines()
    COUNT = 0
    for i in LINES:
        if COUNT > 3:
            line = i.split()
            if 'top' not in line[7: ]:
                if int(line[4]) > MEM_LIMIT:
                    MY_CMD = "SSHPASS='Qube!123' sshpass -e ssh root@" \
                              +SSH_IP +" cat /proc/"+ line[0] + \
                             "/maps | python nmesh_map.py >>" + str(FILE_NAME)
                    FILE_OP = open(FILE_NAME, "a")
                    FILE_OP.write('\n'+ line[7] + '\n\n')
                    FILE_OP.close()
                    os.system(MY_CMD)

        COUNT += 1
    MY_CMD = "rm log.txt"
    os.system(MY_CMD)

    time.sleep(3599)

if __name__ == "__main__":
    while 1:
        log_creator()
