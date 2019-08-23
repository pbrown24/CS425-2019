# Lectures

## Part 1: Game Engine, Game Resouces & Scenes, Modelings

- **Aug 27**: introduction, syllabus [(pdf)](01-overview.pdf)
- **Aug 29**: OGRE (Object-Oriented Graphics Rendering Engine) [(pdf)](02-OGRE.pdf), code (zip files): [(ex01)](CS425App-01-Tutorial%201.zip) [(ex02)](CS425App-02-Simple%20Scene.zip)
  - Exercise 1: Build three inidividual executables from https://github.com/OGRECave/ogre/tree/master/Samples/Tutorials
  - Exercise 2: Read this tutorial https://ogrecave.github.io/ogre/api/latest/setup.html
  - Exercise 3: Convert [(ex02)](CS425App-02-Simple%20Scene.zip) to the current version of OGRE (1.11)
- **Sep 5**: Resouce Management [(pdf)](03-Level%20Loading.pdf)
- **Sep 10**: Scene Management, Octree, BSP, K-D tree, Range tree [(pdf)](04-Scene-Management.pdf)
- **Sep 12**: Level loading Sample Code [(zip)](05-Level%20Loading.zip) (using OGRE 1.11)
  - Exercise 1: Create a level (perhaps of a level of your final project, your room, a classroom, outdoor/indoor scenes, etc)
  - Exercise 2: Extend the code so it includes other types of objects (e.g., passable areas)
  - Exercise 3: (More challenging) Add a visual editor or replace the map with a bitmap or tile map
- **Sep 17**: Procedural Modeling, terrain, L-systems, fractals, City Engine system [(pdf)](06-Procedural-modeling.pdf)
- **Sep 24**: Procedural content, game play [(pdf)](07-procedural-content.pdf)
- **Sep 27**: Human input device [(pdf)](08-HID.pdf)
  - [How Sony Created The Perfect Video Game Controller](https://www.youtube.com/watch?v=3Hm9924cvLI)

## Part 2: Motion, Animation, Physically-based simuation
- **Oct 3**: Introduction to particle system [(pdf)](09-particle-sys.pdf)
- **Oct 9 & 10**: ODE Solvers, Euler's method, Runge-Kutta 2nd~4th order methods, mid-point method [(pdf)](10-ODE.pdf)
- **Oct 15 & 17**: Rigid-body simulation: Part 1 [(pdf)](notesd1.pdf) by David Baraff
  - Dissusion of [programming assignment 3](../assignments/PA03)
- **Oct 22 & 24**: Rigid-body simulation: Part 2 [(pdf)](notesd2.pdf) by David Baraff
  - Dissusion of [programming assignment 4](../assignments/PA4)
- **Oct 29 & 31**: Collision response and conclision [(pdf)](13-rigid-body-collision-response.pdf)
  - Recommended [talk by David Baraff about resting contacts](https://www.youtube.com/watch?v=vNTHveVpDDc)

## Part 3: Game AI
- **Nov 5 & 7** Navigation (e.g., Nav Mesh) & Path finding (A*, D*) [(pdf)](15-Pathfinding.pdf)
  - Pathing http://www.gdcvault.com/play/1014514/AI-Navigation-It-s-Not 
- **Nov 12 & 14**  Path planning, PRM, RRT, etc [(pdf)](16-PathPlanning.pdf)
- **Nov 19 & 26**  Game AI, finite state machines, backward chaining, decision trees, behavior trees, etc, [(pdf)](17-AI.pdf)
  - Unity AI: https://youtu.be/bqsfkGbBU6k?t=222
  - Unity Behavior tree: https://www.youtube.com/watch?v=T_of4_jRoJA
  - UR4 Behavior tree: https://www.youtube.com/watch?v=bsDT95UdPbc
  - Variants of behavior trees http://www.gdcvault.com/play/1012416/Behavior-Trees-Three-Ways-of 
- **Nov 28** Project progress report #2, Decision/Behavior trees practice [(pdf)](18-AI-practice.pptx)
- **Dec 3 & 5** Game AI Tools:
  - [What Makes Good AI? by Game Maker's Toolkit](https://www.youtube.com/watch?v=9bbhJi0NBkk) (16 mins)
  - [Arcade Learning Environment](https://github.com/mgbellemare/Arcade-Learning-Environment)
    - Demo video: https://www.youtube.com/watch?v=nzUiEkasXZI
    - from DeepMind using Deep Q-learning https://www.youtube.com/watch?v=TmPfTpjtdgg
  - ELF: [Extensive, Lightweight, and Flexible platform for game research](https://code.fb.com/ml-applications/introducing-elf-an-extensive-lightweight-and-flexible-platform-for-game-research/)
    - github page: https://github.com/facebookresearch/elf
    - talk (1 hr): https://youtu.be/NaLAveYHQ_U?t=112
    - Demo video: https://www.youtube.com/watch?v=NaLAveYHQ_U
  - Serpent AI: https://github.com/SerpentAI/SerpentAI
    - Example (29 mins): https://www.youtube.com/watch?v=hIFkdao0ELU&t=1s
  - StarCraft II Learning Environment by DeepMind & Blizzard (3 mins): https://www.youtube.com/watch?v=St5lxIxYGkI
  - Deep learning for game developers (49 mins): https://www.youtube.com/watch?v=rF6Usm0tdhk
  - Generative Adversarial Network for procedural content generation
    - generate Mario levels using DCGAN: [paper](https://arxiv.org/pdf/1805.00728.pdf), [video](https://www.youtube.com/watch?v=NObqDuPuk7Q)
    - generate Doom levels using GAN: [paper](https://arxiv.org/pdf/1804.09154.pdf), [video](https://www.youtube.com/watch?v=K32FZ-tjQP4)
  - Machine learning tools by Amazon for game developers (40 mins): https://www.gdcvault.com/browse/gdc-18/play/1024835
    - image recognition to start
    - loot drop starting at 14 min to 19 min.
    - detecting inappropriate contents (images, text)
## Part 4: Other
- **Getting Noticed: Why You Need an Online Portfolio and How to Make One** by Jacob Minkoff
  - https://www.youtube.com/watch?v=yxW0lq47mcE



