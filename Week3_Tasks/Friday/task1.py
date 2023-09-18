import tkinter as tk

def button1Pressed():
    print('Button 1 Pressed.')
def button2Pressed():
    print('Button 2 Pressed.')
def button3Pressed():
    print('Button 3 Pressed.')
def button4Pressed():
    print('Button 4 Pressed.')

window = tk.Tk()
window.title('Task1')
button1= tk.Button(window, text = 'Button1', command = button1Pressed)
button2= tk.Button(window, text = 'Button2', command = button2Pressed)
button3= tk.Button(window, text = 'Button3', command = button3Pressed)
button4= tk.Button(window, text = 'Button4', command = button4Pressed)

button1.grid(row = 1, column = 2)
button2.grid(row = 2, column = 1)
button3.grid(row = 2, column = 3)
button4.grid(row = 3, column = 2)

window.mainloop()

