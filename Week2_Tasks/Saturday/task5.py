import pyautogui
import time

pyautogui.press('win')
time.sleep(1)
pyautogui.write('mail', interval = 0.25)
pyautogui.press('enter')
time.sleep(1)
pyautogui.click(867,146)
time.sleep(1)
pyautogui.press(['down','down'])
pyautogui.press('enter')
time.sleep(1)
pyautogui.click(900,70)
time.sleep(1)
pyautogui.hotkey('ctrl','a')
time.sleep(1)
pyautogui.click(801,69)
time.sleep(1)
pyautogui.press(['down','down','down'])
pyautogui.press('enter')
time.sleep(1)
pyautogui.click(867,146)
time.sleep(1)
pyautogui.press(['up']*2)
pyautogui.press('enter')


