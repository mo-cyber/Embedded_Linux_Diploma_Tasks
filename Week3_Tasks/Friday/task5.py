from tkinter import *

def led_on():
    cnvs.itemconfig(circle, fill = 'red')
    lbl.config(text='Led is on')
def led_off():
    cnvs.itemconfig(circle, fill = 'white')
    lbl.config(text='Led is off')

window = Tk()
window.title('Task 5')

cnvs = Canvas(window, width=200, height=200)
cnvs.pack()

circle = cnvs.create_oval(175, 25, 25, 175, width = 3)

lbl = Label(window, text='Led is off')
b1 = Button(window, text='Led ON', command=led_on)
b2 = Button(window, text='Led OFF', command=led_off)

lbl.pack()
b1.pack()
b2.pack()

mainloop()