// rm.c
//last modified by kissess for log monitoring

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string file)
{
       string filename;
        filename=resolve_path(me->query("cwd"), file);
	seteuid(geteuid(me));
    if (!file) return notify_fail("��Ҫɾ���Ǹ�����?\n");
	if( rm(resolve_path(me->query("cwd"), file)) )
		write("Ok.\n");
	else
		write("��û��ɾ�����������Ȩ����\n");
log_file("cmds/file/rm",
   sprintf("%s(%s) ɾ���ļ� %s �� %s\n",me->name(1), geteuid(me), filename, ctime(time()) ) );
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : rm <����>

��ָ�������ɾ����Ȩ�޸ĵĵ�����
HELP
    );
    return 1;
}
