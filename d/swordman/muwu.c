//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
void create ()
{
    set ("short","����");
  set ("long", @LONG

������һ��ѷ������Сľ�ݣ�����İ���ǳ��ļ�ª��������
һ����������������ˮ�����������Σ��������˽���ǰ�������
��Ļĩ������ŷ�ɢ����ǧ��ն糴�ε�ի��ϵ������
LONG);
   set("exits", ([      
              "south" : __DIR__"liangongshi",
  ]));
   set("objects", ([ 
      __DIR__"npc/jianxin" : 1,
       ]));

  setup();
}









