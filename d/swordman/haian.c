// Room: /changan/aolaiws.c

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_zuo(string arg);
void reset();


void create ()
{
  set ("short", "���֮��");
  set ("long", @LONG

�����Ƕ�孺���������ãã���������߼ʡ������ϲ�����ӿ��
���ɸߵ���ͷ����˷�������Ҫ����һ�и��ڵ����ϵĶ�����
Ҳ���������·�ľ�ͷ����ǰ�Ĵ󺣶�һ��������˵�ǲ�����
Խ�ġ��밶��Զ��Ư��һ��ľ��(chuan)��
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "chuan" : "һ��ľ�����ڰ���������ȥ���㲻������(zuo)��ȥ��һ�ԡ�
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/swordman/gate",
"north":"/d/swordman/searoad1",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
    add_action("do_zuo", "zuo");
    add_action("do_zuo", "sit");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"chuan")) )
            room = load_object(__DIR__"chuan");
        if( room = find_object(__DIR__"chuan") ) {
            if((int)room->query("zuo_trigger")==0 ) {
                room->set("zuo_trigger", 1);
                set("exits/enter", __DIR__"chuan");
                room->set("exits/out", __FILE__);
                message("vision", "һ��ľ���Ӻ���Ư�˹�����\n", this_object() );
                message("vision", "ľ�������Ŀ����ˡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "ľ����ʻ�򰶱ߣ������ӻ������ĵصȵȡ�\n",this_object() );
        }
        else
            message("vision", "ERROR: chuan not found\n", this_object() );
    }
    else 
        message("vision", "ľ���Ѿ������ˣ���ʱ������ȥ��\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "һ����ͷ������ľ������Ưȥ��\n",
        this_object() );

    if( room = find_object(__DIR__"chuan") )
    {
        room->delete("exits/out");
        message("vision", "��Χ�ǰ�ãã��һƬ�����Ѿ��������κ�½�صļ�����...\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"chuan") )
    {
        room->set("exits/out", __DIR__"northseashore");
        message("vision", "ľ��һ�𣬸�ǳ�ˡ���Ȼ�ǵ�½���ˣ��Ͻ���ȥ�ɡ�\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"chuan") ) {
        room->delete("exits/out");
        message("vision","һ����ͷ������ľ������Ưȥ��\n", room);
room->set("zuo_trigger", 0);
    }
}

int do_zuo(string arg)
{
    string dir;

    if( (arg=="chuan") || (arg=="ľ��")){ 
        message_vision("$N����������ľ����\n", this_player());
        check_trigger();
        return 1;
    }
    else return notify_fail("��Ҫ����ʲô��\n");
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"chuan") )
        room->delete("zuo_trigger"); 
}
