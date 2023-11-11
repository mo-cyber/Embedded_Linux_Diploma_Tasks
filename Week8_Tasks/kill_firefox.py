import psutil

def kill_firefox_processes():
    for process in psutil.process_iter(attrs=['pid', 'name']):
        try:
            process_info = process.info
            if process_info['name'] == 'firefox':
                print(f"Killing Firefox process with PID {process_info['pid']}")
                psutil.Process(process_info['pid']).terminate()
        except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
            pass

if __name__ == "__main__":
    kill_firefox_processes()
