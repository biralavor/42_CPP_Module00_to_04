# CPP_template
WIP project list about C++ Modules (0 to 4), from 42 school - @42sp

> [!Important]
> Module 00 is about Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff

https://cplusplus.com/doc/tutorial

https://www.learncpp.com/

## Makefile Targets

A set of convenient Makefile targets is provided to help you work with Docker and development tasks in this project:

| Target         | Description                                                                                   |
|----------------|----------------------------------------------------------------------------------------------|
| **build**      | Build and start the Docker container in detached mode.                                        |
| **go**         | Build/start the container, run preparations, then open an interactive shell in the app.       |
| **stop**       | Stop the running Docker container.                                                            |
| **down**       | Stop and remove the Docker container and associated resources.                                |
| **reload-docker** | Stop, rebuild, and restart the Docker container.                                             |
| **ps**         | List all Docker containers.                                                                   |
| **deep-clean** | Clean up unused Docker builder cache (frees disk space).                                      |

### Usage

To run any of these tasks, use:

```sh
make <target>
