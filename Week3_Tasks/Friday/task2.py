import tkinter as tk

def buttonPressed():
    data = e.get()
    data = data[::-1]
    l2.config(text = data)

window = tk.Tk()
window.title('Task 2')

l1 = tk.Label(window, text = 'Enter a word:')
e = tk.Entry(window, width = 20)
l2 = tk.Label(window, text = '', width = 20)
btn = tk.Button(window, text = 'Validate', command = buttonPressed, width = 17)

l1.grid(row = 1, column = 1, padx = 5, pady = 5)
e.grid(row = 1, column = 2, padx = 5, pady = 5, sticky = 'w')
l2.grid(row = 2, column = 2, padx = 5, pady = 5, sticky = 'w')
btn.grid(row = 3, column = 2, padx = 5, pady = 5, sticky = 'w')

tk.mainloop()
