//kunlun
inherit ROOM;

#include <ansi.h>
void create ()
{
       set ("short", "����");
        set ("long", @LONG

    ���￴�����Ѿ�����·�����ˣ�ǰ����һ�������
Ͽ�ȡ�
LONG);

	set("exits", ([ /* sizeof() == 2 */
                "north" : "/d/moon/yunu1",
        ]));
        set("objects", ([
   ]));
        set("outdoors", "kunlun");
	set("no_clean_up", 0);
        setup();
}
void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object ob;
        int new_sen;
        ob = this_player();
        new_sen = random( ob->query("max_sen")*3 );
        if ( new_sen > ob->query("sen") ) new_sen = ob->query("sen") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
                return notify_fail("����Ҫ������ɱ����ô�벻������\n");
        tell_object(ob,HIR"��̾�˿�������һ�գ�������Ͽ������ȥ������\n"NOR);
        ob->move(__DIR__"qilin");
        tell_object(ob, HIW"����ǰһ����ԭ�����ﾹȻ��һ��������Դ��\n"NOR);
        return 1;
}

