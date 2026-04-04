## Question 2
2.You've seen robotic arms on factory floors — seamlessly grabbing, moving, and placing
objects with surgical precision. Now it's your turn to build one. Model a pick-and-place
robotic arm with a functioning conveyor belt and gripper in MATLAB Simscape
Multibody. The arm must pick an object off the belt, move it, and place it — all
simulated in 3D. The catch? You're getting a broken, unconnected Simscape model as
your starting point. Blocks are there. Wires aren't. Parameters are wrong. Rotations are
missing. You'll need to understand the kinematics, fix the connections, and get the
whole thing running
## Answer
### How did I figure out the connections
I used Claude AI to understand what exactly matlab and its features what is block and ports. I sent the gif video to it told to explain what is exactly happening here in the animataion. Understood the uses of each portsprocess step by step and going through readme helped doing connections and did all the connections.

### 1. Transform Belt Out & Transform Belt In

Frame B connected to the World Frame — sets the physical position of each belt in 3D space.
Frame F connected to the Box to Belt Force blocks — passes the frame location so contact forces can be calculated between the box face and the belt surface.
These transforms were needed to correctly orient each belt along the correct axis so the box slides in the right direction.

### 2. Box to Belt Out Force & Box to Belt In Force

Out port - connected back to the belt transform — outputs the resulting contact force.
PlaB port -  connected to the belt frame — represents the belt's flat plane surface.
FacF port - connected to the box frame — represents the face of the box making contact.
In port - receives the bus signal (bus On) — enables/disables force when the belt is active.
These blocks model planar contact forces between the square box face and the conveyor belt surface.

### 3. Belt Out & Belt In 

Spd port - receives speed input signal — controls how fast the belt moves.
Ctr port - receives control signal — turns the belt on or off.
End port - signals end of belt travel.
Both belts use the same geometric parameters since the box and belt dimensions are matched.

### 4. Damper Gripper Force Block

Connected between the Box and the Gripper subsystem.
Bfa/Bfb ports - connected to Box frame outputs (Fa, Fb) — receives force data from both sides of the box.
Fa/Fb ports - pass forces forward to the Gripper — so the gripper knows how hard to grip.
This block acts as a damper to smooth out the gripping force and prevent sudden force spikes.

### 5. Gripper Subsystem

Contains: Base, Post, Cylindrical Post, Rod, Prismatic Finger A & B, Transform EE, Transform Post Ctr
Finger z (port 1) - controls finger position along z-axis (open/close).
Gripper q (port 2) - outputs gripper joint angle.
Post z (port 3) - controls vertical height of the post.
Post q (port 4) - outputs post joint position.
The two prismatic fingers (A and B) move symmetrically — Finger B is driven by -1 times Finger A signal to mirror the motion.

### 6. Bus Signals

bus On signal connects to both Belt Out and Belt In force blocks.
This enables or disables contact force calculation depending on whether the belt is active at that moment in the simulation sequence.

### 7. In and Out Goto

Used to pass the belt frame references across the diagram without drawing crossing lines.
Out - carries Belt Out frame reference.
In - carries Belt In frame reference.

### What Each Value Represents

### Belt Geometry — Belt Out and Belt In

Conveyor Length (belt_l) = 0.4 m — length of the belt along the travel direction

Conveyor Depth (belt_h) = 0.02 m — thickness of the belt

Conveyor Width (belt_w) = 0.1 m — width of the belt surface

Normal Axis = +Z — belt surface faces upward

Box to Belt Contact Force Parameters

PlaB Length x (belt_l) = 0.4 m — belt contact plane length matches belt size

PlaB Length y (belt_w) = 0.1 m — belt contact plane width matches belt size

PlaB Depth to Ref Frame (belt_h/2) = 0.01 m — half belt thickness, center reference

FacF Length x (cube_d) = 0.06 m — box face is 6 cm wide

FacF Length y (cube_d) = 0.06 m — box face is 6 cm deep

FacF Depth to Ref Frame (cube_d/2) = 0.03 m — half box size, center of box face

FacF Sphere Radius (cube_con_rsph) = 0.003 m — small contact sphere for smooth collision detection
