//Room: hcaguangchang.c �����ֹ㳡
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","�����ֹ㳡");
      set("long",@LONG
�����Ƕ��һ����ֵĹ㳡������������ש����ǰ����һ��̨�ף�ͨ����
�۱����ǰ�и�����ߵĴ���¯����¯ǰ����̨�ϣ�������գ�����Ʈ�ơ�
�㳡���м���Сʦ̫�����������Դ����Ҹ���һ������ͨ���
LONG);
      set("objects", ([
           __DIR__"npc/zhangmen" : 1,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "north"   : __DIR__"hcazhengdian", 
          "southup" : __DIR__"hcadadian", 
          "west"    : __DIR__"hcawest1", 
          "east"    : __DIR__"hcaeast1", 
      ]));
      set("valid_startroom","1");
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
