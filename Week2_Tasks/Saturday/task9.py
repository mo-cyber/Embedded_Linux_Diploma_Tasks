import openpyxl
f = open('E:/Embedded Systems Diploma (MT)/Interfacing 2/7.Keypad and LCD/Keypad_LCD_Eclipse_WS/Exercise1/gpio.h', 'r')
lines = f.readlines()
std_types = ['void', 'uint8', 'sint8', 'uint16', 'sint16', 'uint32', 'sint32', 'uint64', 'sint64', 'float32', 'float64']
prototypes = []
return_type = False
open_bracket = False
close_bracket = False
semicolon = False
counter = 0
for line in lines:
    split = line.split()
    if(len(split) == 0):
        split = ['none']
    if(split[0] in std_types):
        return_type = True
        for check in line:
            if (check == '('):
                open_bracket = True
            if(open_bracket == True and check == ')'):
                close_bracket = True
            if(open_bracket == True and close_bracket == True and check == ';'):
                semicolon = True
    if (return_type == True and open_bracket == True and close_bracket == True and semicolon == True):
        prototypes.append(lines[counter])
    return_type = False
    open_bracket = False
    close_bracket = False
    semicolon = False
    counter += 1

id = 'IDX0'
row = 2
id_num = 1
header_files = openpyxl.Workbook()
prototypes_id = header_files.create_sheet(title = 'prototypes_id')
prototypes_id["A1"] = "Prototype"
prototypes_id["B1"] = "ID"
for i in prototypes:
    prototypes_id["A" + str(row)] = i
    if(id_num < 10):
        prototypes_id["B" + str(row)] = id + "0" + str(id_num)
    else:
        prototypes_id["B" + str(row)] = id + str(id_num)
    row += 1
    id_num += 1
header_files.save("header_files.xlsx")