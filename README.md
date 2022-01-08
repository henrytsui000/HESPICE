# HESPICE

## What's HESPICE
It's a Simulation Program with Integrated Circuit Emphasis(SPICE) build by Ogo and me.

My name is Henry, another collaborator named Ethan, thus the spice Name is 
<font color='red'>H</font>enry
<font color='red'>E</font>than
<font color='red'>S</font>imulation
<font color='red'>P</font>rogram with
<font color='red'>I</font>ntegrated
<font color='red'>C</font>ircuit
<font color='red'>E</font>mphasis

## How to download

```bash
$git clone https://github.com/henrytsui000/HESPICE
```
We don't need any Download dependencies, But we suggest use QT 5.0.1 to open this project

Just double click "./Test/Test.pro" QT will build the environment


## Basic operation

<details>
<summary>opeartions</summary>

### Instructions:

placement interface

Press O or the legend of the resistance to call up the Place Resistance interface

Press L or the legend of the inductor to call up the placement of the Inductance interface

Press C or Capacitor Legend to call up the Place Capacitance interface

Press I or the voltage legend to call up the Voltage Source interface

Press V or the current legend to call up the current source interface

Press W or the legend of the wire to call up the Wire interface


The magnifying glass microscope represents making the circuit bigger or smaller

Scissors are used to remove wires or components

Without pre-selection operation, the left button can drag the whole circuit

Press the left button on the component to "operate"

Right-click on the component to adjust parameters or cancel placement

### Compile Interface

Click the build icon to build the circuit

Press the waveform icon to display SCOPE


Press the left button on the wires to be observed, and then press show to display the waveform
(auto scaled)

Press Cursor to select wires to trace

Move in the Graphics view to measure the time-voltage of a wire

Press Save to save the signal to the specified location

</details>

## Our algorithm


### Simulate Part 

![](https://i.imgur.com/rkS6714.png)

<img src="http://latex.codecogs.com/gif.latex?\begin{bmatrix}
R1 & -R1 & 1\\
-R1 & R1+s \cdot C1 + \frac{1}{s\cdot L1} & 0\\
1 & 0 & 0
\end{bmatrix} 
\begin{bmatrix}
V_1 \\ V_2 \\ I_{v1}
\end{bmatrix}=\begin{bmatrix}
0 \\ 0 \\ V_{v1}
\end{bmatrix} "/>

<img src="http://latex.codecogs.com/gif.latex?\begin{bmatrix}
V_1 \\ V_2 \\ x
\end{bmatrix}
=\sum^{V_{num}}_{i=0}
\begin{bmatrix}
V_{1i} \\ V_{2i} \\ I_{vi}
\end{bmatrix}" />

### Square Wave
<img src="http://latex.codecogs.com/gif.latex?
{\displaystyle {\begin{aligned}x(t)&=\lim_{n\rightarrow	\infty}{\frac {4}{\pi }}\sum _{k=1}^{n}{\frac {\sin \left(2\pi (2k-1)ft\right)}{2k-1}}\\&={\frac {4}{\pi }}\left(\sin(\omega t)+{\frac {1}{3}}\sin(3\omega t)+{\frac {1}{5}}\sin(5\omega t)+\ldots \right),&{\text{where }}\omega =2\pi f.\end{aligned}}} "/>
## Demo Video

The following link is a basic introduction to using this SPICE