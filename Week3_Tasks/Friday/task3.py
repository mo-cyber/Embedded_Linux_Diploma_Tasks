from tkinter import *

def display():
    global v
    operator = v.get()
    operand1 = int(e1.get())
    operand2 = int(e2.get())
    if(operator == 'Sum'):
        answer = operand1 + operand2
        sign = '+'
    elif(operator == 'Sub'):
        answer = operand1 - operand2
        sign = '-'
    lbl3.config(text = f'The {operator} is: {operand1} {sign} {operand2} = {answer}')
    

window = Tk()
window.title('Task 3')
window['padx'] = 20
window['pady'] = 20

v = StringVar()

lbl1 = Label(window, text='Enter the value of M:')
lbl2 = Label(window, text='Enter the value of N:')
lbl3 = Label(window, text='')
e1 = Entry(window, width=20)
e2 = Entry(window, width=20)
rb1 = Radiobutton(window, text='Sum', variable=v, value='Sum')
rb2 = Radiobutton(window, text='Sub', variable=v, value='Sub')
b = Button(window, text='Validate', command=display, width=16)

lbl1.grid(row=1, column=1, padx=5, pady=5)
lbl2.grid(row=2, column=1, padx=5, pady=5)
lbl3.grid(row=3, column=2, padx=5, pady=5)
e1.grid(row=1, column=2, padx=5, pady=5)
e2.grid(row=2, column=2, padx=5, pady=5)
rb1.grid(row=4, column=1, sticky='w', padx=5, pady=5)
rb2.grid(row=5, column=1, sticky='w', padx=5, pady=5)
b.grid(row=4, column=2)

v=''

mainloop()


