# airo2_assignment_2


# Description
The first step in running the project successfully is to install the popf-tif planner (which can be found in this [repository](https://github.com/popftif/popf-tif )).

If you use the docker ubuntu image, take in mind that the planner is based on the Ubuntu-22.04 Docker Official Image, which lacks a graphical interface.
To change the planning files, use the following command to mount a shared directory between your host machine and the docker image: 
// docker run -dit -v path/in_your/host/folder:path/in/docker_container/folder --name your_name hypothe/ai4ro2_2

The docker image given by Dr.Antony Thomas , is the simplest method to execute the project. This image already includes all of the necessary setup to execute the project.
Simply extract the visits_domain and visits_module folders included with this repository and replace them in the '/root/ai4ro2' directory. 

The visits_domain folder contains a PDDL domain as well as issue files, whereas the visits_module folder contains the files required to execute the external planner.



## Refrences used
The poptf repository : https://github.com/popftif/popf-tif 

The docker image given by Dr.Antony Thomas : https://hub.docker.com/r/hypothe/ai4ro2_2
