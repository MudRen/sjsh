inherit ROOM;

void create()
{
        set("short", "���ķ�");
        set("long",@LONG

     ���������ǳ��������绢���̾١�
     ��ħС����һ����ʤ֮���䡣
     ������ͼ��Ѫ����𣬾��鳾ʿ��
        ���������죬��Ե���ڣ�
     �շ�ף�Ϧ���£��ư��ʾ����
         "Ϊ˭�����軨��·��
     �������ǣ��������ã���֦��¶��
    �����ٻ�����������������ξ塣"
    ������֮�ˣ�����֮�£���Ӣ��ŭ��


LONG
        );
        set("exits", 
        ([          
           "south" : __DIR__"workroom",
                
        ]));


        set("valid_startroom", 1);

        setup();
        
}

void init()
{   
          add_action("block_cmd","",1);         
}

int block_cmd()
{
        string verb = query_verb();
        
        if (verb=="say") return 0; //allow say
        if (verb=="look") return 0;
        if (verb=="south") return 0;
        if (verb=="edit") return 0;
        if (verb=="update") return 0;
        if (verb=="ls") return 0;
        if (verb=="cd") return 0;
        if (verb=="rm") return 0;
        if (verb=="cp") return 0;
        if (verb=="goto") return 0;
        if (verb=="home") return 0;
        if (verb=="more") return 0;
        if (verb=="cat") return 0;
        if (verb=="who") return 0;
        return 1;
}

