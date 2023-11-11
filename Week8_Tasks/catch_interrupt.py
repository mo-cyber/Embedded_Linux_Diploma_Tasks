import signal
import sys
import time

def sigint_handler(signal, frame):
    print("\nExit")
    sys.exit(0)

signal.signal(signal.SIGINT, sigint_handler)

try:
    while True:
        print("\nWaiting interrupt signal..")
        time.sleep(1)
        pass
except KeyboardInterrupt:
    pass