
void draw_branch(GLfloat size, GLfloat length)
{
	GLUquadricObj *pObj; // Quadric object
	pObj =gluNewQuadric();
	gluQuadricNormals(pObj, GLU_SMOOTH);
	
	glPushMatrix();
	gluSphere(pObj, size, 26, 13);
	gluCylinder(pObj, size, size, length, 26, 13);
	glTranslatef(0.0f, 0.0f, length);
	gluSphere(pObj, size, 26, 13);
	glPopMatrix();	
}

void divide_branch_third(int n, GLfloat size, GLfloat length)
{
	if(n){
		if(n<4)
		glColor3ub(107, 79, 65); //brigth dark brown (young branch)
		else glColor3ub(92, 64, 51); //dark brown (branch)

		glPushMatrix();
		draw_branch(size, length); //main branch
		glTranslatef(0.0, 0.0, length);
		glRotatef(45, 0.0, 1.0, 0.0);
		divide_branch_third(n-1, size*0.7, length*0.7); //right branch
		if(n>3){
		glRotatef(-90, 0.0, 1.0, 0.0);
		divide_branch_third(n-1, size*0.5, length*0.5); //left branch
		if(n>2){
		glRotatef(-90, 1.0, 0.0, 1.0);
		divide_branch_third(n-1, size*0.7, length*0.3); //upper branch
		if(n>1){
		glRotatef(90, 0.0, 01.0, 0.0);
		divide_branch_third(n-1, size*0.6, length*0.7); //lower branch
		}}}
		glPopMatrix();
	}
	else{
		glPushMatrix();
		glColor3ub(0, 100, 0); //brigth dark green (leaf)
		glScalef(2.0, 0.5, 1.0);
		draw_branch(0.5, 0.3);
		glPopMatrix();
	}
}