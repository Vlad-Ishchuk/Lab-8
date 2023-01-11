#include <iostream>
using namespace std;

struct People
{
	string name;
	int age;
};

struct Object
{
	People data;
	Object* left;
	Object* right;
};

Object* new_object(People p);
void show_object(Object* newObject);
void show_tree(Object* root);


int main()
{
	People i = { "Vova", 19 };
	People mom = { "Olena", 45 };
	People dad = { "Volodymyr", 46 };
	People MGranny = { "Olga", 69 };
	People MGrandpa = { "Serhiy", 72 };

	Object* root = new_object(i);

	root->right = new_object(mom);
	root->left = new_object(dad);

	root->right->right = new_object(MGranny);
	root->right->left = new_object(MGrandpa);

	show_tree(root);
}

Object* new_object(People p)
{
	Object* newObject = new Object();
	newObject->data = p;
	newObject->left = NULL;
	newObject->right = NULL;
	return newObject;
}

void show_object(Object* newObject)
{
	if (newObject == NULL)
		return;
	cout << newObject->data.name << ", " << newObject->data.age << endl;
	show_object(newObject->left);
	show_object(newObject->right);
}

void show_tree(Object* root)
{
	if (root == NULL)
		return;
	cout << root->data.name << ", " << root->data.age << endl;
	show_object(root->left);
	show_object(root->right);
}