//kunlun
inherit ROOM;

void create ()
{
        set ("short", "���Ƹ�");
        set ("long", @LONG
    ����������̻Ի��������𣬸������������룬��ǽ�
���ܣ�������ǽ���ԧ��˫˫�Զԣ�������һ�����������
̨�����Ϸ�����Ϣ�ҡ����洫��������������
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "south" : __DIR__"shijie1",
                "north" : __DIR__"lianwu",
                "southeast" : __DIR__"xiuxishi",
        ]));
        set("objects", ([ 
                __DIR__"npc/jinzha" : 1,

   ]));
       setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "southeast" ) {
        if (objectp(present("jin zha", environment(me)))) {
        if((string)me->query("family/family_name")=="����ɽ���鶴") {
        return ::valid_leave(me, dir);
        }
        return notify_fail("��߸�ȵ����㲻�Ǳ��ŵ��ӣ��ǲ������ȥ�ĵط���\n");
        }
        }
        return ::valid_leave(me, dir);
}

