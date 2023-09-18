from tkinter import *
import math

def factorial():
    n = int(e.get())
    fact = math.factorial(n)
    lbl2.config(text=f'The factorial of {n} is {n}! = {fact}')

window = Tk()
window.title('Task 6')
window['padx'] = 20
window['pady'] = 20

lbl1 = Label(window, text='Enter value of integer N:')
lbl2 = Label(window)
e = Entry(window, width=20)
btn = Button(window, text='Validate', command=factorial, width=17)

lbl1.grid(row=1, column=1, padx=5, pady=5)
lbl2.grid(row=2, column=2, padx=5, pady=5)
e.grid(row=1, column=2, padx=5, pady=5)
btn.grid(row=3, column=2, padx=5, pady=5)

mainloop()