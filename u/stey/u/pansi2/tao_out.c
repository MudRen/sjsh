#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�һ�����");
        set("long",@LONG
����һƬ�һ��ĺ�������һ���޼ʣ�ȫ��ʢ�����һ���΢�������
��Ӣ�ͷס���Χ�����ĵġ�Զ��ż������һ����С�������һƬ��
���֣�����Զ��ңң�������¡¡��ˮ��,�ƺ��и��ٲ���
LONG );
       set("exits", ([
           "south" : __DIR__"tao0",
           "north" : __DIR__"pubu",
       ]));
       set("outdoors","taohua");
       set("no_clean_up", 0);
       setup();
}
void init()
{       object ob;
        mapping myfam;
        if( interactive( ob = this_player()))
        if(query("exits/north")) 
			myfam = (mapping)ob->query("family");
        if(myfam && myfam["family_name"] == "��˿��")
        {
            delete("exits/south");
            set("exits/south", __DIR__"tao_in");
            return ;
        }       
        if ((int)ob->query_skill("spells",1) > 100 )
        {
            delete("exits/north");
            set("exits/north", __DIR__"tao_in");
            return ;
        }
           
  	delete("exits/north");
        set("exits/north", __DIR__"pubu");
}
