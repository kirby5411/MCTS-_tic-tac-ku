from tkinter import *
import time
import tkinter.messagebox
import subprocess
tk = Tk()
tk.title("Tic Tac Toe")

pa = StringVar()
playerb = StringVar()
p1 = StringVar()
p2 = StringVar()


endgame = False
bclick = True
flag = [0,0,0,0,0,0,0,0,0]
wins = [' ',' ',' ',' ',' ',' ',' ',' ',' ']

command = ["MCTS_tic-tak-ku.exe"]

proc = subprocess.Popen(
        command, stdin=subprocess.PIPE, stdout=subprocess.PIPE ,encoding="utf-8", bufsize=1
    )

def disableButton():
   button1.configure(state=DISABLED, bg="gray")
   button2.configure(state=DISABLED, bg="gray")
   button3.configure(state=DISABLED, bg="gray")
   button4.configure(state=DISABLED, bg="gray")
   button5.configure(state=DISABLED, bg="gray")
   button6.configure(state=DISABLED, bg="gray")
   button7.configure(state=DISABLED, bg="gray")
   button8.configure(state=DISABLED, bg="gray")
   button9.configure(state=DISABLED, bg="gray")
   button10.configure(state=DISABLED, bg="gray")
   button11.configure(state=DISABLED, bg="gray")
   button12.configure(state=DISABLED, bg="gray")
   button13.configure(state=DISABLED, bg="gray")
   button14.configure(state=DISABLED, bg="gray")
   button15.configure(state=DISABLED, bg="gray")
   button16.configure(state=DISABLED, bg="gray")
   button17.configure(state=DISABLED, bg="gray")
   button18.configure(state=DISABLED, bg="gray")
   button19.configure(state=DISABLED, bg="gray")
   button20.configure(state=DISABLED, bg="gray")
   button21.configure(state=DISABLED, bg="gray")
   button22.configure(state=DISABLED, bg="gray")
   button23.configure(state=DISABLED, bg="gray")
   button24.configure(state=DISABLED, bg="gray")
   button25.configure(state=DISABLED, bg="gray")
   button26.configure(state=DISABLED, bg="gray")
   button27.configure(state=DISABLED, bg="gray")
   button28.configure(state=DISABLED, bg="gray")
   button29.configure(state=DISABLED, bg="gray")
   button30.configure(state=DISABLED, bg="gray")
   button31.configure(state=DISABLED, bg="gray")
   button32.configure(state=DISABLED, bg="gray")
   button33.configure(state=DISABLED, bg="gray")
   button34.configure(state=DISABLED, bg="gray")
   button35.configure(state=DISABLED, bg="gray")
   button36.configure(state=DISABLED, bg="gray")
   button37.configure(state=DISABLED, bg="gray")
   button38.configure(state=DISABLED, bg="gray")
   button39.configure(state=DISABLED, bg="gray")
   button40.configure(state=DISABLED, bg="gray")
   button41.configure(state=DISABLED, bg="gray")
   button42.configure(state=DISABLED, bg="gray")
   button43.configure(state=DISABLED, bg="gray")
   button44.configure(state=DISABLED, bg="gray")
   button45.configure(state=DISABLED, bg="gray")
   button46.configure(state=DISABLED, bg="gray")
   button47.configure(state=DISABLED, bg="gray")
   button48.configure(state=DISABLED, bg="gray")
   button49.configure(state=DISABLED, bg="gray")
   button50.configure(state=DISABLED, bg="gray")
   button51.configure(state=DISABLED, bg="gray")
   button52.configure(state=DISABLED, bg="gray")
   button53.configure(state=DISABLED, bg="gray")
   button54.configure(state=DISABLED, bg="gray")
   button55.configure(state=DISABLED, bg="gray")
   button56.configure(state=DISABLED, bg="gray")
   button57.configure(state=DISABLED, bg="gray")
   button58.configure(state=DISABLED, bg="gray")
   button59.configure(state=DISABLED, bg="gray")
   button60.configure(state=DISABLED, bg="gray")
   button61.configure(state=DISABLED, bg="gray")
   button62.configure(state=DISABLED, bg="gray")
   button63.configure(state=DISABLED, bg="gray")
   button64.configure(state=DISABLED, bg="gray")
   button65.configure(state=DISABLED, bg="gray")
   button66.configure(state=DISABLED, bg="gray")
   button67.configure(state=DISABLED, bg="gray")
   button68.configure(state=DISABLED, bg="gray")
   button69.configure(state=DISABLED, bg="gray")
   button70.configure(state=DISABLED, bg="gray")
   button71.configure(state=DISABLED, bg="gray")
   button72.configure(state=DISABLED, bg="gray")
   button73.configure(state=DISABLED, bg="gray")
   button74.configure(state=DISABLED, bg="gray")
   button75.configure(state=DISABLED, bg="gray")
   button76.configure(state=DISABLED, bg="gray")
   button77.configure(state=DISABLED, bg="gray")
   button78.configure(state=DISABLED, bg="gray")
   button79.configure(state=DISABLED, bg="gray")
   button80.configure(state=DISABLED, bg="gray")
   button81.configure(state=DISABLED, bg="gray")

def enableButton():
  button1.configure(state=NORMAL, bg="gray")
  button2.configure(state=NORMAL, bg="gray")
  button3.configure(state=NORMAL, bg="gray")
  button4.configure(state=NORMAL, bg="gray")
  button5.configure(state=NORMAL, bg="gray")
  button6.configure(state=NORMAL, bg="gray")
  button7.configure(state=NORMAL, bg="gray")
  button8.configure(state=NORMAL, bg="gray")
  button9.configure(state=NORMAL, bg="gray")
  button10.configure(state=NORMAL, bg="gray")
  button11.configure(state=NORMAL, bg="gray")
  button12.configure(state=NORMAL, bg="gray")
  button13.configure(state=NORMAL, bg="gray")
  button14.configure(state=NORMAL, bg="gray")
  button15.configure(state=NORMAL, bg="gray")
  button16.configure(state=NORMAL, bg="gray")
  button17.configure(state=NORMAL, bg="gray")
  button18.configure(state=NORMAL, bg="gray")
  button19.configure(state=NORMAL, bg="gray")
  button20.configure(state=NORMAL, bg="gray")
  button21.configure(state=NORMAL, bg="gray")
  button22.configure(state=NORMAL, bg="gray")
  button23.configure(state=NORMAL, bg="gray")
  button24.configure(state=NORMAL, bg="gray")
  button25.configure(state=NORMAL, bg="gray")
  button26.configure(state=NORMAL, bg="gray")
  button27.configure(state=NORMAL, bg="gray")
  button28.configure(state=NORMAL, bg="gray")
  button29.configure(state=NORMAL, bg="gray")
  button30.configure(state=NORMAL, bg="gray")
  button31.configure(state=NORMAL, bg="gray")
  button32.configure(state=NORMAL, bg="gray")
  button33.configure(state=NORMAL, bg="gray")
  button34.configure(state=NORMAL, bg="gray")
  button35.configure(state=NORMAL, bg="gray")
  button36.configure(state=NORMAL, bg="gray")
  button37.configure(state=NORMAL, bg="gray")
  button38.configure(state=NORMAL, bg="gray")
  button39.configure(state=NORMAL, bg="gray")
  button40.configure(state=NORMAL, bg="gray")
  button41.configure(state=NORMAL, bg="gray")
  button42.configure(state=NORMAL, bg="gray")
  button43.configure(state=NORMAL, bg="gray")
  button44.configure(state=NORMAL, bg="gray")
  button45.configure(state=NORMAL, bg="gray")
  button46.configure(state=NORMAL, bg="gray")
  button47.configure(state=NORMAL, bg="gray")
  button48.configure(state=NORMAL, bg="gray")
  button49.configure(state=NORMAL, bg="gray")
  button50.configure(state=NORMAL, bg="gray")
  button51.configure(state=NORMAL, bg="gray")
  button52.configure(state=NORMAL, bg="gray")
  button53.configure(state=NORMAL, bg="gray")
  button54.configure(state=NORMAL, bg="gray")
  button55.configure(state=NORMAL, bg="gray")
  button56.configure(state=NORMAL, bg="gray")
  button57.configure(state=NORMAL, bg="gray")
  button58.configure(state=NORMAL, bg="gray")
  button59.configure(state=NORMAL, bg="gray")
  button60.configure(state=NORMAL, bg="gray")
  button61.configure(state=NORMAL, bg="gray")
  button62.configure(state=NORMAL, bg="gray")
  button63.configure(state=NORMAL, bg="gray")
  button64.configure(state=NORMAL, bg="gray")
  button65.configure(state=NORMAL, bg="gray")
  button66.configure(state=NORMAL, bg="gray")
  button67.configure(state=NORMAL, bg="gray")
  button68.configure(state=NORMAL, bg="gray")
  button69.configure(state=NORMAL, bg="gray")
  button70.configure(state=NORMAL, bg="gray")
  button71.configure(state=NORMAL, bg="gray")
  button72.configure(state=NORMAL, bg="gray")
  button73.configure(state=NORMAL, bg="gray")
  button74.configure(state=NORMAL, bg="gray")
  button75.configure(state=NORMAL, bg="gray")
  button76.configure(state=NORMAL, bg="gray")
  button77.configure(state=NORMAL, bg="gray")
  button78.configure(state=NORMAL, bg="gray")
  button79.configure(state=NORMAL, bg="gray")
  button80.configure(state=NORMAL, bg="gray")
  button81.configure(state=NORMAL, bg="gray")

def enableBig1():
   disableButton();
   button1.configure(state=NORMAL, bg="red")
   button2.configure(state=NORMAL, bg="red")
   button3.configure(state=NORMAL, bg="red")
   button10.configure(state=NORMAL, bg="red")
   button11.configure(state=NORMAL, bg="red")
   button12.configure(state=NORMAL, bg="red")
   button19.configure(state=NORMAL, bg="red")
   button20.configure(state=NORMAL, bg="red")
   button21.configure(state=NORMAL, bg="red")
def enableBig2():
   disableButton();
   button4.configure(state=NORMAL, bg="red")
   button5.configure(state=NORMAL, bg="red")
   button6.configure(state=NORMAL, bg="red")
   button13.configure(state=NORMAL, bg="red")
   button14.configure(state=NORMAL, bg="red")
   button15.configure(state=NORMAL, bg="red")
   button22.configure(state=NORMAL, bg="red")
   button23.configure(state=NORMAL, bg="red")
   button24.configure(state=NORMAL, bg="red")
def enableBig3():
   disableButton();
   button7.configure(state=NORMAL, bg="red")
   button8.configure(state=NORMAL, bg="red")
   button9.configure(state=NORMAL, bg="red")
   button16.configure(state=NORMAL, bg="red")
   button17.configure(state=NORMAL, bg="red")
   button18.configure(state=NORMAL, bg="red")
   button25.configure(state=NORMAL, bg="red")
   button26.configure(state=NORMAL, bg="red")
   button27.configure(state=NORMAL, bg="red")

def enableBig4():
   disableButton();
   button28.configure(state=NORMAL, bg="red")
   button29.configure(state=NORMAL, bg="red")
   button30.configure(state=NORMAL, bg="red")
   button37.configure(state=NORMAL, bg="red")
   button38.configure(state=NORMAL, bg="red")
   button39.configure(state=NORMAL, bg="red")
   button46.configure(state=NORMAL, bg="red")
   button47.configure(state=NORMAL, bg="red")
   button48.configure(state=NORMAL, bg="red")

def enableBig5():
   disableButton();
   button31.configure(state=NORMAL, bg="red")
   button32.configure(state=NORMAL, bg="red")
   button33.configure(state=NORMAL, bg="red")
   button40.configure(state=NORMAL, bg="red")
   button41.configure(state=NORMAL, bg="red")
   button42.configure(state=NORMAL, bg="red")
   button49.configure(state=NORMAL, bg="red")
   button50.configure(state=NORMAL, bg="red")
   button51.configure(state=NORMAL, bg="red")

def enableBig6():
   disableButton();
   button34.configure(state=NORMAL, bg="red")
   button35.configure(state=NORMAL, bg="red")
   button36.configure(state=NORMAL, bg="red")
   button43.configure(state=NORMAL, bg="red")
   button44.configure(state=NORMAL, bg="red")
   button45.configure(state=NORMAL, bg="red")
   button52.configure(state=NORMAL, bg="red")
   button53.configure(state=NORMAL, bg="red")
   button54.configure(state=NORMAL, bg="red")

def enableBig7():
   disableButton();
   button55.configure(state=NORMAL, bg="red")
   button56.configure(state=NORMAL, bg="red")
   button57.configure(state=NORMAL, bg="red")
   button64.configure(state=NORMAL, bg="red")
   button65.configure(state=NORMAL, bg="red")
   button66.configure(state=NORMAL, bg="red")
   button73.configure(state=NORMAL, bg="red")
   button74.configure(state=NORMAL, bg="red")
   button75.configure(state=NORMAL, bg="red")
def enableBig8():
   disableButton();
   button58.configure(state=NORMAL, bg="red")
   button59.configure(state=NORMAL, bg="red")
   button60.configure(state=NORMAL, bg="red")
   button67.configure(state=NORMAL, bg="red")
   button68.configure(state=NORMAL, bg="red")
   button69.configure(state=NORMAL, bg="red")
   button76.configure(state=NORMAL, bg="red")
   button77.configure(state=NORMAL, bg="red")
   button78.configure(state=NORMAL, bg="red")

def enableBig9():
   disableButton();
   button61.configure(state=NORMAL, bg="red")
   button62.configure(state=NORMAL, bg="red")
   button63.configure(state=NORMAL, bg="red")
   button70.configure(state=NORMAL, bg="red")
   button71.configure(state=NORMAL, bg="red")
   button72.configure(state=NORMAL, bg="red")
   button79.configure(state=NORMAL, bg="red")
   button80.configure(state=NORMAL, bg="red")
   button81.configure(state=NORMAL, bg="red")


def checkForWin():
    winBig1()
    winBig2()
    winBig3()
    winBig4()
    winBig5()
    winBig6()
    winBig7()
    winBig8()
    winBig9()

def countboard(buttons):
    global flag
    if ((buttons == button1 or buttons == button2 or buttons == button3 or 
        buttons == button10 or buttons == button11 or buttons == button12 or 
        buttons == button19 or buttons == button20 or buttons == button21) and 
        winBig1() == ' '):
        flag[0]=flag[0]+1
    elif ((buttons == button4 or buttons == button5 or buttons == button6 or 
        buttons == button13 or buttons == button14 or buttons == button15 or 
        buttons == button22 or buttons == button23 or buttons == button24) and 
        winBig2() == ' '):
        flag[1]=flag[1]+1
    elif ((buttons == button7 or buttons == button8 or buttons == button9 or 
        buttons == button16 or buttons == button17 or buttons == button18 or 
        buttons == button25 or buttons == button26 or buttons == button27) and 
        winBig3() == ' '):
        flag[2]=flag[2]+1
    elif ((buttons == button28 or buttons == button29 or buttons == button30 or 
        buttons == button37 or buttons == button38 or buttons == button39 or 
        buttons == button46 or buttons == button47 or buttons == button48) and 
        winBig4() == ' '):
        flag[3]=flag[3]+1
    elif ((buttons == button31 or buttons == button32 or buttons == button33 or 
        buttons == button40 or buttons == button41 or buttons == button42 or 
        buttons == button49 or buttons == button50 or buttons == button51) and 
        winBig5() == ' '):
        flag[4]=flag[4]+1
    elif ((buttons == button34 or buttons == button35 or buttons == button36 or 
        buttons == button43 or buttons == button44 or buttons == button45 or 
        buttons == button52 or buttons == button53 or buttons == button54) and 
        winBig6() == ' '):
        flag[5]=flag[5]+1
    elif ((buttons == button55 or buttons == button56 or buttons == button57 or 
        buttons == button64 or buttons == button65 or buttons == button66 or 
        buttons == button73 or buttons == button74 or buttons == button75) and 
        winBig7() == ' '):
        flag[6]=flag[6]+1
    elif ((buttons == button58 or buttons == button59 or buttons == button60 or 
        buttons == button67 or buttons == button68 or buttons == button69 or 
        buttons == button76 or buttons == button77 or buttons == button78) and 
        winBig8() == ' '):
        flag[7]=flag[7]+1
    elif ((buttons == button61 or buttons == button62 or buttons == button63 or 
        buttons == button70 or buttons == button71 or buttons == button72 or 
        buttons == button79 or buttons == button80 or buttons == button81) and 
        winBig9() == ' '):
        flag[8]=flag[8]+1

def rules(buttons):
    print("button is", buttons,"\n")
    if ((buttons == button1 or buttons == button4 or buttons == button7 or 
        buttons == button28 or buttons == button31 or buttons == button34 or 
        buttons == button55 or buttons == button58 or buttons == button61) and 
        winBig1() == ' '):
        enableBig1()
    elif ((buttons == button2 or buttons == button5 or buttons == button8 or 
        buttons == button29 or buttons == button32 or buttons == button35 or 
        buttons == button56 or buttons == button59 or buttons == button62) and 
        winBig2() == ' '):
        enableBig2()
    elif ((buttons == button3 or buttons == button6 or buttons == button9 or 
        buttons == button30 or buttons == button33 or buttons == button36 or 
        buttons == button57 or buttons == button60 or buttons == button63) and 
        winBig3() == ' '):
        enableBig3()
    elif ((buttons == button10 or buttons == button13 or buttons == button16 or 
        buttons == button37 or buttons == button40 or buttons == button43 or 
        buttons == button64 or buttons == button67 or buttons == button70) and 
        winBig4() == ' '):
        enableBig4()
    elif ((buttons == button11 or buttons == button14 or buttons == button17 or 
        buttons == button38 or buttons == button41 or buttons == button44 or 
        buttons == button65 or buttons == button68 or buttons == button71) and 
        winBig5() == ' '):
        enableBig5()
    elif ((buttons == button12 or buttons == button15 or buttons == button18 or 
        buttons == button39 or buttons == button42 or buttons == button45 or 
        buttons == button66 or buttons == button69 or buttons == button72) and 
        winBig6() == ' '):
        enableBig6()
    elif ((buttons == button19 or buttons == button22 or buttons == button25 or 
        buttons == button46 or buttons == button49 or buttons == button52 or 
        buttons == button73 or buttons == button76 or buttons == button79) and 
        winBig7() == ' '):
        enableBig7()
    elif ((buttons == button20 or buttons == button23 or buttons == button26 or 
        buttons == button47 or buttons == button50 or buttons == button53 or 
        buttons == button74 or buttons == button77 or buttons == button80) and 
        winBig8() == ' '):
        enableBig8()
    elif ((buttons == button21 or buttons == button24 or buttons == button27 or 
        buttons == button48 or buttons == button51 or buttons == button54 or 
        buttons == button75 or buttons == button78 or buttons == button81) and 
        winBig9() == ' '):
        enableBig9()
    else:
        enableButton()
        print("enable all button \n")

def identify_button_by_row_and_column(parent, row, column):
    for child in parent.winfo_children():
        info = child.grid_info()                            
        if info['row'] == row and info['column'] == column:
            return child

def AIplay(AIrowandcolumn):
    AIrow = AIrowandcolumn // 10
    AIcolumn = AIrowandcolumn % 10
    global bclick
    print(AIrow,"\n",AIcolumn,"\n")
    AImove = identify_button_by_row_and_column(tk,AIrow,AIcolumn)
    print("AI move is ",AImove)
    if(AImove['text'] == ' '  and bclick == False):
        AImove['text'] = 'X'
        bclick = True
        return AImove
    else:
        print("Error on AI")

def btnClick(buttons):
    global bclick, flag, endgame
    count = 0
    player1 = 0
    player2 = 0
    playerrow  = buttons.grid_info()['row']
    playercolumn = buttons.grid_info()['column']
    if buttons['text'] == ' '  and bclick == True:
        buttons['text'] = 'O'
        bclick = False
        countboard(buttons)
        checkForWin()
        rules(buttons)
        print(playerrow, "," , playercolumn)
        proc.stdin.write("player\n")
        temps = str(playerrow*10+playercolumn)
        proc.stdin.write(temps+"\n")
    elif buttons['text'] == ' '  and bclick == False:
        tkinter.messagebox.showinfo("Tic-Tac-Toe", "AI's turn!")
    else:
        tkinter.messagebox.showinfo("Tic-Tac-Toe", "Button already Clicked!")
    for x in range (9):
        count=count+flag[x]
        if(wins[x]=='O'):
          player1 = player1+1
        elif(wins[x]=='X'):
          player2 = player2+1
    if(count==81):
        if(player1>player2):
          winmes = "O won!"
        else:
          winmes = "X won!"
        tkinter.messagebox.showinfo("Tic-Tac-Toe", "Game End! "+winmes)
        endgame = True
    if(endgame==False):
        proc.stdin.write("genmove\n")
        AIRandC = proc.stdout.readline()
        AIRandC = int(AIRandC)
        AIbutton = AIplay(AIRandC)
        countboard(AIbutton)
        checkForWin()
        print("before rules button",AIbutton,"\n")
        rules(AIbutton)
        count = 0
        player1 = 0
        player2 = 0
        for x in range (9):
            count=count+flag[x]
            if(wins[x]=='O'):
              player1 = player1+1
            elif(wins[x]=='X'):
              player2 = player2+1
        if(count==81):
            if(player1>player2):
              winmes = "O won!"
            else:
              winmes = "X won!"
            tkinter.messagebox.showinfo("Tic-Tac-Toe", "Game End!"+winmes)
            endgame = True
    
def winBig1():
    if (button1['text'] == 'X' and button2['text'] == 'X' and button3['text'] == 'X' or
        button10['text'] == 'X' and button11['text'] == 'X' and button12['text'] == 'X' or
        button19['text'] =='X' and button20['text'] == 'X' and button21['text'] == 'X' or
        button1['text'] == 'X' and button11['text'] == 'X' and button21['text'] == 'X' or
        button3['text'] == 'X' and button11['text'] == 'X' and button19['text'] == 'X' or
        button1['text'] == 'X' and button10['text'] == 'X' and button19['text'] == 'X' or
        button2['text'] == 'X' and button11['text'] == 'X' and button20['text'] == 'X' or
        button3['text'] == 'X' and button12['text'] == 'X' and button21['text'] == 'X'):
        button1['text'] = 'X' 
        button2['text'] = 'X'
        button3['text'] = 'X' 
        button10['text'] = 'X'
        button11['text'] = 'X'
        button12['text'] = 'X' 
        button19['text'] ='X'
        button20['text'] = 'X'
        button21['text'] = 'X'
        if(flag[0]<9):
          flag[0]=9
        if(wins[0]==' '):
          wins[0]='X'
        return 'X'
    elif (button1['text'] == 'O' and button2['text'] == 'O' and button3['text'] == 'O' or
        button10['text'] == 'O' and button11['text'] == 'O' and button12['text'] == 'O' or
        button19['text'] =='O' and button20['text'] == 'O' and button21['text'] == 'O' or
        button1['text'] == 'O' and button11['text'] == 'O' and button21['text'] == 'O' or
        button3['text'] == 'O' and button11['text'] == 'O' and button19['text'] == 'O' or
        button1['text'] == 'O' and button10['text'] == 'O' and button19['text'] == 'O' or
        button2['text'] == 'O' and button11['text'] == 'O' and button20['text'] == 'O' or
        button3['text'] == 'O' and button12['text'] == 'O' and button21['text'] == 'O'):
        button1['text'] = 'O' 
        button2['text'] = 'O'
        button3['text'] = 'O' 
        button10['text'] = 'O'
        button11['text'] = 'O'
        button12['text'] = 'O' 
        button19['text'] ='O'
        button20['text'] = 'O'
        button21['text'] = 'O'
        if(flag[0]<9):
          flag[0]=9
        if(wins[0]==' '):
          wins[0]='O'
        return 'O'
    else:
        return ' '
        
def winBig2():
    if (button4['text'] == 'X' and button5['text'] == 'X' and button6['text'] == 'X' or
        button13['text'] == 'X' and button14['text'] == 'X' and button15['text'] == 'X' or
        button22['text'] =='X' and button23['text'] == 'X' and button24['text'] == 'X' or
        button4['text'] == 'X' and button14['text'] == 'X' and button24['text'] == 'X' or
        button6['text'] == 'X' and button14['text'] == 'X' and button22['text'] == 'X' or
        button4['text'] == 'X' and button13['text'] == 'X' and button22['text'] == 'X' or
        button5['text'] == 'X' and button14['text'] == 'X' and button23['text'] == 'X' or
        button6['text'] == 'X' and button15['text'] == 'X' and button24['text'] == 'X'):
        button4['text'] = 'X' 
        button5['text'] = 'X' 
        button6['text'] = 'X' 
        button13['text'] = 'X' 
        button14['text'] = 'X'
        button15['text'] = 'X' 
        button22['text'] ='X' 
        button23['text'] = 'X' 
        button24['text'] = 'X' 
        if(flag[1]<9):
          flag[1]=9
        if(wins[1]==' '):
          wins[1]='X'
        return 'X'
    elif (button4['text'] == 'O' and button5['text'] == 'O' and button6['text'] == 'O' or
        button13['text'] == 'O' and button14['text'] == 'O' and button15['text'] == 'O' or
        button22['text'] =='O' and button23['text'] == 'O' and button24['text'] == 'O' or
        button4['text'] == 'O' and button14['text'] == 'O' and button24['text'] == 'O' or
        button6['text'] == 'O' and button14['text'] == 'O' and button22['text'] == 'O' or
        button4['text'] == 'O' and button13['text'] == 'O' and button22['text'] == 'O' or
        button5['text'] == 'O' and button14['text'] == 'O' and button23['text'] == 'O' or
        button6['text'] == 'O' and button15['text'] == 'O' and button24['text'] == 'O'):
        button4['text'] = 'O'
        button5['text'] = 'O'
        button6['text'] = 'O'
        button13['text'] = 'O'
        button14['text'] = 'O'
        button15['text'] = 'O'
        button22['text'] ='O'
        button23['text'] = 'O'
        button24['text'] = 'O'
        if(flag[1]<9):
          flag[1]=9
        if(wins[1]==' '):
          wins[1]='O'
        return 'O'
    else:
        return ' '

def winBig3():
    if (button7['text'] == 'X' and button8['text'] == 'X' and button9['text'] == 'X' or
        button16['text'] == 'X' and button17['text'] == 'X' and button18['text'] == 'X' or
        button25['text'] =='X' and button26['text'] == 'X' and button27['text'] == 'X' or
        button7['text'] == 'X' and button17['text'] == 'X' and button27['text'] == 'X' or
        button9['text'] == 'X' and button17['text'] == 'X' and button25['text'] == 'X' or
        button7['text'] == 'X' and button16['text'] == 'X' and button25['text'] == 'X' or
        button8['text'] == 'X' and button17['text'] == 'X' and button26['text'] == 'X' or
        button9['text'] == 'X' and button18['text'] == 'X' and button27['text'] == 'X'):
        button7['text'] = 'X'
        button8['text'] = 'X'
        button9['text'] = 'X'
        button16['text'] = 'X'
        button17['text'] = 'X'
        button18['text'] = 'X'
        button25['text'] ='X'
        button26['text'] = 'X'
        button27['text'] = 'X'
        if(flag[2]<9):
          flag[2]=9
        if(wins[2]==' '):
          wins[2]='X'
        return 'X'
    elif (button7['text'] == 'O' and button8['text'] == 'O' and button9['text'] == 'O' or
        button16['text'] == 'O' and button17['text'] == 'O' and button18['text'] == 'O' or
        button25['text'] =='O' and button26['text'] == 'O' and button27['text'] == 'O' or
        button7['text'] == 'O' and button17['text'] == 'O' and button27['text'] == 'O' or
        button9['text'] == 'O' and button17['text'] == 'O' and button25['text'] == 'O' or
        button7['text'] == 'O' and button16['text'] == 'O' and button25['text'] == 'O' or
        button8['text'] == 'O' and button17['text'] == 'O' and button26['text'] == 'O' or
        button9['text'] == 'O' and button18['text'] == 'O' and button27['text'] == 'O'):
        button7['text'] = 'O'
        button8['text'] = 'O'
        button9['text'] = 'O'
        button16['text'] = 'O'
        button17['text'] = 'O'
        button18['text'] = 'O'
        button25['text'] ='O'
        button26['text'] = 'O'
        button27['text'] = 'O'
        if(flag[2]<9):
          flag[2]=9
        if(wins[2]==' '):
          wins[2]='O'
        return 'O'
    else:
        return ' '

def winBig4():
    if (button28['text'] == 'X' and button29['text'] == 'X' and button30['text'] == 'X' or
        button37['text'] == 'X' and button38['text'] == 'X' and button39['text'] == 'X' or
        button46['text'] == 'X' and button47['text'] == 'X' and button48['text'] == 'X' or
        button28['text'] == 'X' and button38['text'] == 'X' and button48['text'] == 'X' or
        button30['text'] == 'X' and button38['text'] == 'X' and button46['text'] == 'X' or
        button28['text'] == 'X' and button37['text'] == 'X' and button46['text'] == 'X' or
        button29['text'] == 'X' and button38['text'] == 'X' and button47['text'] == 'X' or
        button30['text'] == 'X' and button39['text'] == 'X' and button48['text'] == 'X'):
        button28['text'] = 'X'
        button29['text'] = 'X'
        button30['text'] = 'X'
        button37['text'] = 'X'
        button38['text'] = 'X'
        button39['text'] = 'X'
        button46['text'] = 'X'
        button47['text'] = 'X'
        button48['text'] = 'X'
        if(flag[3]<9):
          flag[3]=9
        if(wins[3]==' '):
          wins[3]='X'
        return 'X'
    elif (button28['text'] == 'O' and button29['text'] == 'O' and button30['text'] == 'O' or
        button37['text'] == 'O' and button38['text'] == 'O' and button39['text'] == 'O' or
        button46['text'] == 'O' and button47['text'] == 'O' and button48['text'] == 'O' or
        button28['text'] == 'O' and button38['text'] == 'O' and button48['text'] == 'O' or
        button30['text'] == 'O' and button38['text'] == 'O' and button46['text'] == 'O' or
        button28['text'] == 'O' and button37['text'] == 'O' and button46['text'] == 'O' or
        button29['text'] == 'O' and button38['text'] == 'O' and button47['text'] == 'O' or
        button30['text'] == 'O' and button39['text'] == 'O' and button48['text'] == 'O'):
        button28['text'] = 'O'
        button29['text'] = 'O'
        button30['text'] = 'O'
        button37['text'] = 'O'
        button38['text'] = 'O'
        button39['text'] = 'O'
        button46['text'] = 'O'
        button47['text'] = 'O'
        button48['text'] = 'O'
        if(flag[3]<9):
          flag[3]=9
        if(wins[3]==' '):
          wins[3]='O'
        return 'O'
    else:
        return ' '

def winBig5():
    if (button31['text'] =='X' and button32['text'] == 'X' and button33['text'] == 'X' or
        button40['text'] == 'X' and button41['text'] == 'X' and button42['text'] == 'X' or
        button49['text'] == 'X' and button50['text'] == 'X' and button51['text'] == 'X' or
        button31['text'] == 'X' and button41['text'] == 'X' and button51['text'] == 'X' or
        button33['text'] == 'X' and button41['text'] == 'X' and button49['text'] == 'X' or
        button31['text'] == 'X' and button40['text'] == 'X' and button49['text'] == 'X' or
        button32['text'] == 'X' and button41['text'] == 'X' and button50['text'] == 'X' or
        button33['text'] == 'X' and button42['text'] == 'X' and button51['text'] == 'X'):
        button31['text'] = 'X'
        button32['text'] = 'X'
        button33['text'] = 'X'
        button40['text'] = 'X'
        button41['text'] = 'X'
        button42['text'] = 'X'
        button49['text'] = 'X'
        button50['text'] = 'X'
        button51['text'] = 'X'
        if(flag[4]<9):
          flag[4]=9
        if(wins[4]==' '):
          wins[4]='X'
        return 'X'
    elif (button31['text'] =='O' and button32['text'] == 'O' and button33['text'] == 'O' or
        button40['text'] == 'O' and button41['text'] == 'O' and button42['text'] == 'O' or
        button49['text'] == 'O' and button50['text'] == 'O' and button51['text'] == 'O' or
        button31['text'] == 'O' and button41['text'] == 'O' and button51['text'] == 'O' or
        button33['text'] == 'O' and button41['text'] == 'O' and button49['text'] == 'O' or
        button31['text'] == 'O' and button40['text'] == 'O' and button49['text'] == 'O' or
        button32['text'] == 'O' and button41['text'] == 'O' and button50['text'] == 'O' or
        button33['text'] == 'O' and button42['text'] == 'O' and button51['text'] == 'O'):
        button31['text'] = 'O'
        button32['text'] = 'O'
        button33['text'] = 'O'
        button40['text'] = 'O'
        button41['text'] = 'O'
        button42['text'] = 'O'
        button49['text'] = 'O'
        button50['text'] = 'O'
        button51['text'] = 'O'
        if(flag[4]<9):
          flag[4]=9
        if(wins[4]==' '):
          wins[4]='O'
        return 'O'
    else:
        return ' '
def winBig6():
    if (button34['text'] == 'X' and button35['text'] == 'X' and button36['text'] == 'X' or
        button43['text'] == 'X' and button44['text'] == 'X' and button45['text'] == 'X' or
        button52['text'] =='X' and button53['text'] == 'X' and button54['text'] == 'X' or
        button34['text'] == 'X' and button44['text'] == 'X' and button54['text'] == 'X' or
        button36['text'] == 'X' and button44['text'] == 'X' and button52['text'] == 'X' or
        button34['text'] == 'X' and button43['text'] == 'X' and button52['text'] == 'X' or
        button35['text'] == 'X' and button44['text'] == 'X' and button53['text'] == 'X' or
        button36['text'] == 'X' and button45['text'] == 'X' and button54['text'] == 'X'):
        button34['text'] = 'X'
        button35['text'] = 'X'
        button36['text'] = 'X'
        button43['text'] = 'X'
        button44['text'] = 'X'
        button45['text'] = 'X'
        button52['text'] = 'X'
        button53['text'] = 'X'
        button54['text'] = 'X'
        if(flag[5]<9):
          flag[5]=9
        if(wins[5]==' '):
          wins[5]='X'
        return 'X'
    elif (button34['text'] == 'O' and button35['text'] == 'O' and button36['text'] == 'O' or
        button43['text'] == 'O' and button44['text'] == 'O' and button45['text'] == 'O' or
        button52['text'] =='O' and button53['text'] == 'O' and button54['text'] == 'O' or
        button34['text'] == 'O' and button44['text'] == 'O' and button54['text'] == 'O' or
        button36['text'] == 'O' and button44['text'] == 'O' and button52['text'] == 'O' or
        button34['text'] == 'O' and button43['text'] == 'O' and button52['text'] == 'O' or
        button35['text'] == 'O' and button44['text'] == 'O' and button53['text'] == 'O' or
        button36['text'] == 'O' and button45['text'] == 'O' and button54['text'] == 'O'):
        button34['text'] = 'O'
        button35['text'] = 'O'
        button36['text'] = 'O'
        button43['text'] = 'O'
        button44['text'] = 'O'
        button45['text'] = 'O'
        button52['text'] = 'O'
        button53['text'] = 'O'
        button54['text'] = 'O'
        if(flag[5]<9):
          flag[5]=9
        if(wins[5]==' '):
          wins[5]='O'
        return 'O'
    else:
        return ' '
        
def winBig7():
    if (button55['text'] =='X' and button56['text'] == 'X' and button57['text'] == 'X' or
        button64['text'] == 'X' and button65['text'] == 'X' and button66['text'] == 'X' or
        button73['text'] =='X' and button74['text'] == 'X' and button75['text'] == 'X' or
        button55['text'] == 'X' and button65['text'] == 'X' and button75['text'] == 'X' or
        button57['text'] == 'X' and button65['text'] == 'X' and button73['text'] == 'X' or
        button55['text'] == 'X' and button64['text'] == 'X' and button73['text'] == 'X' or
        button56['text'] == 'X' and button65['text'] == 'X' and button74['text'] == 'X' or
        button57['text'] == 'X' and button66['text'] == 'X' and button75['text'] == 'X'):
        button55['text'] = 'X'
        button56['text'] = 'X'
        button57['text'] = 'X'
        button64['text'] = 'X'
        button65['text'] = 'X'
        button66['text'] = 'X'
        button73['text'] = 'X'
        button74['text'] = 'X'
        button75['text'] = 'X'
        if(flag[6]<9):
          flag[6]=9
        if(wins[0]==' '):
          wins[0]='X'
        return 'X'
    elif (button55['text'] =='O' and button56['text'] == 'O' and button57['text'] == 'O' or
        button64['text'] == 'O' and button65['text'] == 'O' and button66['text'] == 'O' or
        button73['text'] =='O' and button74['text'] == 'O' and button75['text'] == 'O' or
        button55['text'] == 'O' and button65['text'] == 'O' and button75['text'] == 'O' or
        button57['text'] == 'O' and button65['text'] == 'O' and button73['text'] == 'O' or
        button55['text'] == 'O' and button64['text'] == 'O' and button73['text'] == 'O' or
        button56['text'] == 'O' and button65['text'] == 'O' and button74['text'] == 'O' or
        button57['text'] == 'O' and button66['text'] == 'O' and button75['text'] == 'O'):
        button55['text'] = 'O'
        button56['text'] = 'O'
        button57['text'] = 'O'
        button64['text'] = 'O'
        button65['text'] = 'O'
        button66['text'] = 'O'
        button73['text'] = 'O'
        button74['text'] = 'O'
        button75['text'] = 'O'
        if(flag[6]<9):
          flag[6]=9
        if(wins[6]==' '):
          wins[6]='O'
        return 'O'
    else:
        return ' '

def winBig8():
    if (button58['text'] =='X' and button59['text'] == 'X' and button60['text'] == 'X' or
        button67['text'] == 'X' and button68['text'] == 'X' and button69['text'] == 'X' or
        button76['text'] =='X' and button77['text'] == 'X' and button78['text'] == 'X' or
        button58['text'] == 'X' and button68['text'] == 'X' and button78['text'] == 'X' or
        button60['text'] == 'X' and button68['text'] == 'X' and button76['text'] == 'X' or
        button58['text'] == 'X' and button67['text'] == 'X' and button76['text'] == 'X' or
        button59['text'] == 'X' and button68['text'] == 'X' and button77['text'] == 'X' or
        button60['text'] == 'X' and button69['text'] == 'X' and button78['text'] == 'X'):
        button58['text'] = 'X'
        button59['text'] = 'X'
        button60['text'] = 'X'
        button67['text'] = 'X'
        button68['text'] = 'X'
        button69['text'] = 'X'
        button76['text'] = 'X'
        button77['text'] = 'X'
        button78['text'] = 'X'
        if(flag[7]<9):
          flag[7]=9
        if(wins[7]==' '):
          wins[7]='X'
        return 'X'
    elif (button58['text'] =='O' and button59['text'] == 'O' and button60['text'] == 'O' or
        button67['text'] == 'O' and button68['text'] == 'O' and button69['text'] == 'O' or
        button76['text'] =='O' and button77['text'] == 'O' and button78['text'] == 'O' or
        button58['text'] == 'O' and button68['text'] == 'O' and button78['text'] == 'O' or
        button60['text'] == 'O' and button68['text'] == 'O' and button76['text'] == 'O' or
        button58['text'] == 'O' and button67['text'] == 'O' and button76['text'] == 'O' or
        button59['text'] == 'O' and button68['text'] == 'O' and button77['text'] == 'O' or
        button60['text'] == 'O' and button69['text'] == 'O' and button78['text'] == 'O'):
        button58['text'] = 'O'
        button59['text'] = 'O'
        button60['text'] = 'O'
        button67['text'] = 'O'
        button68['text'] = 'O'
        button69['text'] = 'O'
        button76['text'] = 'O'
        button77['text'] = 'O'
        button78['text'] = 'O'
        if(flag[7]<9):
          flag[7]=9
        if(wins[7]==' '):
          wins[7]='O'
        return 'O'
    else:
        return ' '

def winBig9():
    if (button61['text'] == 'X' and button62['text'] == 'X' and button63['text'] == 'X' or
        button70['text'] == 'X' and button71['text'] == 'X' and button72['text'] == 'X' or
        button79['text'] =='X' and button80['text'] == 'X' and button81['text'] == 'X' or
        button61['text'] == 'X' and button71['text'] == 'X' and button81['text'] == 'X' or
        button63['text'] == 'X' and button71['text'] == 'X' and button79['text'] == 'X' or
        button61['text'] == 'X' and button70['text'] == 'X' and button79['text'] == 'X' or
        button62['text'] == 'X' and button71['text'] == 'X' and button80['text'] == 'X' or
        button63['text'] == 'X' and button72['text'] == 'X' and button81['text'] == 'X'):
        button61['text'] = 'X'
        button62['text'] = 'X'
        button63['text'] = 'X'
        button70['text'] = 'X'
        button71['text'] = 'X'
        button72['text'] = 'X'
        button79['text'] = 'X'
        button80['text'] = 'X'
        button81['text'] = 'X'
        if(flag[8]<9):
          flag[8]=9
        if(wins[8]==' '):
          wins[8]='X'
        return 'X'
    elif (button61['text'] == 'O' and button62['text'] == 'O' and button63['text'] == 'O' or
        button70['text'] == 'O' and button71['text'] == 'O' and button72['text'] == 'O' or
        button79['text'] =='O' and button80['text'] == 'O' and button81['text'] == 'O' or
        button61['text'] == 'O' and button71['text'] == 'O' and button81['text'] == 'O' or
        button63['text'] == 'O' and button71['text'] == 'O' and button79['text'] == 'O' or
        button61['text'] == 'O' and button70['text'] == 'O' and button79['text'] == 'O' or
        button62['text'] == 'O' and button71['text'] == 'O' and button80['text'] == 'O' or
        button63['text'] == 'O' and button72['text'] == 'O' and button81['text'] == 'O'):
        button61['text'] = 'O'
        button62['text'] = 'O'
        button63['text'] = 'O'
        button70['text'] = 'O'
        button71['text'] = 'O'
        button72['text'] = 'O'
        button79['text'] = 'O'
        button80['text'] = 'O'
        button81['text'] = 'O'
        if(flag[8]<9):
          flag[8]=9
        if(wins[8]==' '):
          wins[8]='O'
        return 'O'
    else:
        return ' '




buttons = StringVar()
 
button1 = Button(tk, text=" ", font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button1))
button1.grid(row=0, column=0)
 
button2 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button2))
button2.grid(row=0, column=1)
 
button3 = Button(tk, text=' ',font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button3))
button3.grid(row=0, column=2)
 
button4 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button4))
button4.grid(row=0, column=3)
 
button5 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button5))
button5.grid(row=0, column=4)
 
button6 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button6))
button6.grid(row=0, column=5)
 
button7 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button7))
button7.grid(row=0, column=6)
 
button8 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button8))
button8.grid(row=0, column=7)
 
button9 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button9))
button9.grid(row=0, column=8)
 
button10 = Button(tk, text=" ", font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button10))
button10.grid(row=1, column=0)
 
button11 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button11))
button11.grid(row=1, column=1)
 
button12 = Button(tk, text=' ',font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button12))
button12.grid(row=1, column=2)
 
button13 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button13))
button13.grid(row=1, column=3)
 
button14 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button14))
button14.grid(row=1, column=4)
 
button15 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button15))
button15.grid(row=1, column=5)
 
button16 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button16))
button16.grid(row=1, column=6)
 
button17 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button17))
button17.grid(row=1, column=7)
 
button18 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button18))
button18.grid(row=1, column=8)
 
button19 = Button(tk, text=" ", font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button19))
button19.grid(row=2, column=0)
 
button20 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button20))
button20.grid(row=2, column=1)
 
button21 = Button(tk, text=' ',font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button21))
button21.grid(row=2, column=2)
 
button22 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button22))
button22.grid(row=2, column=3)
 
button23 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button23))
button23.grid(row=2, column=4)
 
button24 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button24))
button24.grid(row=2, column=5)
 
button25 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button25))
button25.grid(row=2, column=6)
 
button26 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button26))
button26.grid(row=2, column=7)
 
button27 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button27))
button27.grid(row=2, column=8)
 
button28 = Button(tk, text=" ", font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button28))
button28.grid(row=3, column=0)
 
button29 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button29))
button29.grid(row=3, column=1)
 
button30 = Button(tk, text=' ',font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button30))
button30.grid(row=3, column=2)
 
button31 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button31))
button31.grid(row=3, column=3)
 
button32 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button32))
button32.grid(row=3, column=4)
 
button33 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button33))
button33.grid(row=3, column=5)
 
button34 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button34))
button34.grid(row=3, column=6)
 
button35 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button35))
button35.grid(row=3, column=7)
 
button36 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button36))
button36.grid(row=3, column=8)
 
button37 = Button(tk, text=" ", font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button37))
button37.grid(row=4, column=0)
 
button38 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button38))
button38.grid(row=4, column=1)
 
button39 = Button(tk, text=' ',font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button39))
button39.grid(row=4, column=2)
 
button40 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button40))
button40.grid(row=4, column=3)
 
button41 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button41))
button41.grid(row=4, column=4)
 
button42 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button42))
button42.grid(row=4, column=5)
 
button43 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button43))
button43.grid(row=4, column=6)
 
button44 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button44))
button44.grid(row=4, column=7)
 
button45 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button45))
button45.grid(row=4, column=8)
 
button46 = Button(tk, text=" ", font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button46))
button46.grid(row=5, column=0)
 
button47 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button47))
button47.grid(row=5, column=1)
 
button48 = Button(tk, text=' ',font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button48))
button48.grid(row=5, column=2)
 
button49 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button49))
button49.grid(row=5, column=3)
 
button50 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button50))
button50.grid(row=5, column=4)
 
button51 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button51))
button51.grid(row=5, column=5)
 
button52 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button52))
button52.grid(row=5, column=6)
 
button53 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button53))
button53.grid(row=5, column=7)
 
button54 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button54))
button54.grid(row=5, column=8)
 
button55 = Button(tk, text=" ", font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button55))
button55.grid(row=6, column=0)
 
button56 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button56))
button56.grid(row=6, column=1)
 
button57 = Button(tk, text=' ',font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button57))
button57.grid(row=6, column=2)
 
button58 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button58))
button58.grid(row=6, column=3)
 
button59 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button59))
button59.grid(row=6, column=4)
 
button60 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button60))
button60.grid(row=6, column=5)
 
button61 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button61))
button61.grid(row=6, column=6)
 
button62 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button62))
button62.grid(row=6, column=7)
 
button63 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button63))
button63.grid(row=6, column=8)
 
button64 = Button(tk, text=" ", font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button64))
button64.grid(row=7, column=0)
 
button65 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button65))
button65.grid(row=7, column=1)
 
button66 = Button(tk, text=' ',font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button66))
button66.grid(row=7, column=2)
 
button67 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button67))
button67.grid(row=7, column=3)
 
button68 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button68))
button68.grid(row=7, column=4)
 
button69 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button69))
button69.grid(row=7, column=5)
 
button70 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button70))
button70.grid(row=7, column=6)
 
button71 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button71))
button71.grid(row=7, column=7)
 
button72 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button72))
button72.grid(row=7, column=8)
 
button73 = Button(tk, text=" ", font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button73))
button73.grid(row=8, column=0)
 
button74 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button74))
button74.grid(row=8, column=1)
 
button75 = Button(tk, text=' ',font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button75))
button75.grid(row=8, column=2)
 
button76 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button76))
button76.grid(row=8, column=3)
 
button77 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button77))
button77.grid(row=8, column=4)
 
button78 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button78))
button78.grid(row=8, column=5)
 
button79 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button79))
button79.grid(row=8, column=6)
 
button80 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button80))
button80.grid(row=8, column=7)
 
button81 = Button(tk, text=' ', font='Times 20 bold', bg='gray', fg='white', height=1, width=2, command=lambda: btnClick(button81))
button81.grid(row=8, column=8)

tk.mainloop()
