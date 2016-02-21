inherit ROOM;
int do_open(string arg);
int do_close(string arg);

void create()
{
        set("short", "��ʥ���±���");
        set("long",@LONG 

    ����һ�����Ĵ�������һ����Լ��ʮ��ߵķ��汦��ͨ��
���ҫ�ۡ������������ƣ����������������̴ľ������������һ����
ɼ����(gate)����
LONG );
        set("exits", ([
  "north" : __DIR__"taijie",
  "east" : __DIR__"zoulang3",
        ])); 
set("valid_startroom", 1);
    set("item_desc",([ 
        "gate" : "һ���������ߵ����ɼľ��ͭ���š�\n"
    ]));
        set("objects",([
         "/d/nanhai/npc/shami" : 1,
     __DIR__"npc/heshang" : 2,
        ]));
//        set("no_clean_up", 0);
        setup();
//        replace_program(ROOM);
}
 
void init()
{
        add_action("do_open", "open");
        add_action("do_close", "close");
}
void close_gate()
{
        object room;

        if(!( room = find_object("/d/nanhai/frontgate")) )
                room = load_object("/d/nanhai/frontgate");
        if(objectp(room))
        {
                delete("exits/south");
                        message("vision", "Сɳ����ǰ�Ѵ��Ź���������\n", this_object());
                room->delete("exits/north");
                message("vision", "ƹ��һ�����������˰Ѵ��Ź����ˡ�\n", room);
        }
} 

int do_close(string arg)
{
        if (!query("exits/south"))
                return notify_fail("�����Ѿ��ǹ��ŵ��ˡ�\n");

        if (!arg || (arg != "gate" && arg != "south"))
                return notify_fail("��Ҫ��ʲô��\n");

        message_vision("$N��Сɳ�ֵ��˵�ͷ��\n", this_player());

        remove_call_out("close_gate");
        call_out("close_gate", 2);

        return 1;
} 

int do_open(string arg)
{
        object room;

        if (query("exits/south"))
                return notify_fail("�����Ѿ��ǿ����ˡ�\n");

        if (!arg || (arg != "gate" && arg != "south"))
                return notify_fail("��Ҫ��ʲô��\n");

        if(!( room = find_object("/d/nanhai/frontgate")) )
                room = load_object("/d/nanhai/frontgate");
        if(objectp(room))
        {
                set("exits/south", "/d/nanhai/frontgate");
                message_vision("$Nʹ���Ѵ��Ŵ��˿�����\n", this_player());
                room->set("exits/north", __FILE__);
                message("vision", "֨��һ�����������˰Ѵ��Ŵ��ˡ�\n", room);
                remove_call_out("close_gate");
                call_out("close_gate", 10);
        }

        return 1;
}

