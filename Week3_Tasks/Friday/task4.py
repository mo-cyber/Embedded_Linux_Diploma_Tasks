from tkinter import *
import random

def update_guage():
    random_value = random.randint(0,100)
    cnvs.itemconfig(result, text = str(random_value) + '%')
    angle = 120 * (100 - random_value) / (100 - 0) + 30
    cnvs.itemconfig(needle, start = angle)
    window.after(3000, update_guage)

window = Tk()
window.title('Task 4')

cnvs = Canvas(window, width=400, height=300)
cnvs.grid(row=2, column=1)

for i in range(8):
    cnvs.create_arc(10,50,350,350, start = (i*(120/8) + 30), extent = (120/8), fill = 'white', width = 1)

cnvs.create_arc(10,50,350,350, start = 30, extent = 120, outline = 'green', style = 'arc', width = 40)
cnvs.create_arc(10,50,350,350, start = 30, extent = 20, outline = 'red', style = 'arc', width = 40)
cnvs.create_arc(10,50,350,350, start = 50, extent = 20, outline = 'yellow', style = 'arc', width = 40)
needle = cnvs.create_arc(10,50,350,350, start = 119, extent = 1, width = 7)

cnvs.create_text(180, 20, font = 'Times 20 italic bold', text = 'Humidity')
cnvs.create_text(25, 140, font = 'Times 12 bold', text = 0)
cnvs.create_text(330, 140, font = 'Times 12 bold', text = 100)
result = cnvs.create_text(170, 210, font = 'Times 15 bold', text = '25%')

window.after(3000, update_guage)


mainloop()