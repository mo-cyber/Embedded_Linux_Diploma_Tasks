import pyautogui
import time

#Open VScode
pyautogui.hotkey('win')
pyautogui.typewrite('visual studio code')
pyautogui.hotkey('enter')
time.sleep(2)

#Maximize window
pyautogui.hotkey('win','up')

#Open extensions
pyautogui.hotkey('ctrl','shift','x')

#Install clangd
pyautogui.click(287,132) #Move and click the mouse to write
time.sleep(2)
pyautogui.typewrite('clangd')
time.sleep(2)
pyautogui.click(450,249) #Move and click the mouse to install position
time.sleep(2)
pyautogui.click(445,75) #Move and click the mouse to clear search
time.sleep(2)

#Install c++ testmate
pyautogui.click(287,132) #Move and click the mouse to write
time.sleep(2)
pyautogui.typewrite('c++ testmate')
time.sleep(2)
pyautogui.click(450,249) #Move and click the mouse to install position
time.sleep(2)
pyautogui.click(445,75) #Move and click the mouse to clear search
time.sleep(2)

#Install c++ helper
pyautogui.click(287,132) #Move and click the mouse to write
time.sleep(2)
pyautogui.typewrite('c++ helper')
time.sleep(2)
pyautogui.click(450,249) #Move and click the mouse to install position
time.sleep(2)
pyautogui.click(445,75) #Move and click the mouse to clear search
time.sleep(2)

#Install cmake
pyautogui.click(287,132) #Move and click the mouse to write
time.sleep(2)
pyautogui.typewrite('cmake')
time.sleep(2)
pyautogui.click(450,249) #Move and click the mouse to install position
time.sleep(2)
pyautogui.click(445,75) #Move and click the mouse to clear search
time.sleep(2)

#Install cmake tools
pyautogui.click(287,132) #Move and click the mouse to write
time.sleep(2)
pyautogui.typewrite('cmake tools')
time.sleep(2)
pyautogui.click(450,249) #Move and click the mouse to install position
time.sleep(2)
pyautogui.click(445,75) #Move and click the mouse to clear search
time.sleep(2)


