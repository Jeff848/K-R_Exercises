/*
 ============================================================================
 Name        : LearnOpenGL.c
 Author      : Jeffrey
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include </System/Library/Frameworks/OpenGL.framework/Headers/glext.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;

    glutInit(&argc, argv);
    ...
    glewInit();

    if (glewIsSupported("GL_VERSION_3_3"))
        printf("Ready for OpenGL 3.3\n");
    else {
        printf("OpenGL 3.3 not supported\n");
        exit(1);
    }

    setShaders();
    initGL();

        glutMainLoop();
}
