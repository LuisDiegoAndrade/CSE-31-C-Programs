from pylatex import Document, Section, Subsection, Figure, NoEscape, Math, VectorName



def latex():

    doc = Document()
    with doc.create(Section('TPS Activity 2')):
        doc.append('1) gcc -g -o execName sourcename.c')
        doc.append(Math(data=['\linebreak'], escape=False))
        doc.append('2) lldb execName')
        doc.append(Math(data=['\linebreak'], escape=False))
        doc.append('3) Shortcut "r"')
        doc.append(Math(data=['\linebreak'], escape=False))
        doc.append('4) Lets you stop the flow of exection at a particular line. In lldb use "b sourcefile.c:linenumber"')
        doc.append(Math(data=['\linebreak'], escape=False))
        doc.append('5) Using shortcut "n"')
        doc.append(Math(data=['\linebreak'], escape=False))
        doc.append('6) Using "p VARIABLENAME"')
        doc.append(Math(data=['\linebreak'], escape=False))
        doc.append('7) Using "continue"')
        doc.append(Math(data=['\linebreak'], escape=False))
        doc.append('8) Using "exit"')

    with doc.create(Section('TPS Activity 3')):
        doc.append('1) 4')
        doc.append(Math(data=['\linebreak'], escape=False))
        doc.append('2) x, y, and arr[0] have all been declared, but not initialized. Most likely there might be something stored at the memory allocated for these variables.')
        doc.append(Math(data=['\linebreak'], escape=False))
        doc.append('3) By initializing the variables.')
        doc.append(Math(data=['\linebreak'], escape=False))
        doc.append('8) Yes because they are both pointing to the same address in memory')
        doc.append(Math(data=['\pagebreak'], escape=False))


    with doc.create(Section('Assignment 1')):
        doc.append('1) 4')
        doc.append(Math(data=['\linebreak'], escape=False))
        doc.append('2) Line 15, scanf() is given an incorrect parameter. scanf() needs the variable input address. E.g scanf("%d", &input)')
        doc.append(Math(data=['\linebreak'], escape=False))
        doc.append('3) The function read_values() is not manipulation the variable sum defined in main.')
        doc.append(Math(data=['\linebreak'], escape=False))
        doc.append('4) We can pass in sums address to the function, so a pointer within this function can manipulate sums value.')
        doc.append(Math(data=['\linebreak'], escape=False))

    with doc.create(Section('Assignment 2')):
        doc.append("We need to allocate enough memory in str1 to be able to concate both strings without truncating any values.")
        doc.append(Math(data=['\linebreak'], escape=False))


    #print(doc.dumps())

    with open('lab2.tex','w') as f:
        f.write(doc.dumps())



if __name__ == '__main__':

    latex()
