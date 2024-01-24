#include <python.h>
#include <object.h>
#include <listobject.h>

void print_python_list_info(pyobject *)
{
	long int size = pyList_size(p);
	int i;
	pyListObject *obj = (pyListObject *)p;

	printf("[*] size of the python = %li\n", size);
	printf("[*] Allocated = %li\n," obj-allocated;
			for (i = 0; i < size; i++)
			printf("Element %1: %s\n", i, py_TYPE(ob_item[i])->tp_name);
}
