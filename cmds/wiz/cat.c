// cat.c
// Modified by island@fyzx

int main(object me, string arg)
{
        string file;

        seteuid(geteuid(me));

        if (me != this_player())
                return 0;

        if (! arg) return notify_fail("ָ���ʽ :cat <������>\n");
        file = resolve_path(me->query("cwd"), arg);
        if (file_size(file) < 0)
                return notify_fail("û�����������\n");

        if (! SECURITY_D->valid_read(file, me, "cat"))
                return notify_fail("û�����������\n");

        if (file_size(file) > 100000 )
                write("�ļ�̫�������� more ָ��鿴��\n");
        else
                me->start_more(read_file(file));
       log_file("cmds/file/cat", 
        sprintf("[%s] %s cat %s \n",ctime(time()) , geteuid(me), file ) );

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ :cat <������>

���ָ��������Բ���һ���ļ������ݡ�

see also: more
HELP );
    return 1;
}
