// news.c
// ��Ҫ�޸ĵ��ļ���

#include <ansi.h>;
inherit BULLETIN_BOARD;

void create()
{
	set_name("���������Ű�", ({ "newsboard"}) );
	set("location", "/d/wiz/jobroom"); 
	set("board_id", "newsall_b");  
	setup();
	set("capacity", 500);
}

// ���������������loginʱ���õġ�
int check_news(object me)
{
	int num,i,last_time_read;
	mapping *notes, last_read_time;
	string myid,msg="";
	notes = query("notes");
	last_read_time =me->query("board_last_read"+(string)query("board_id"));
	myid = query("board_id");
	if( !pointerp(notes) || !sizeof(notes) ) return 1;

 	if(userp(me))
	{
		i=sizeof(notes)-me->query("LastReadNews");
		
		if(i < 6 && i > 0) // С��6�����Ų���ʾ���⣬��Ȼ��FLOOD
		{
			msg =CYN"\n��"YEL"���������������������ũ���������������������������������������������������"CYN"��\n"NOR;
			
			if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
				num = 1;
				
			else
				for(num = 1; num<=sizeof(notes); num++)
					if( notes[num-1]["time"] > last_read_time[myid] ) break;
					
			if (mapp(last_read_time)) last_time_read = last_read_time[myid];
			for(i=sizeof(notes)-1 ; i>num-2 ; i--)
			{
				msg += sprintf(YEL"��"NOR"%3d"YEL"��"NOR,i+1);
				msg += sprintf("     %-=25s %18s (%s)\n",
					notes[i]["title"], notes[i]["author"],
					RTIME_D->chinese_time(5, ctime(notes[i]["time"])));
			}
			
			msg += CYN"��"YEL"�������������������������������������������������������������񻰩�����������"CYN"��"NOR;
			me->start_more(msg);
		}
		
		i=sizeof(notes)-me->query("LastReadNews");
		write(BRED YEL"�����羫�顿�������������ϴο����ŵ�����"+((i==0)? "û���κ�":"����"+WHT+chinese_number(i)+YEL"��")+"���ţ�\n"NOR);
		if(i>10) write("�����Help news ���鿴���������š��Ĳ鿴������\n"); // ���Ѳ�֪����NEWSϵͳ�����ʹ��news
	}
}
int main(object me, string arg)
{
	int num,i,last_time_read;
	mapping *notes, last_read_time;
	string myid,msg;

	last_read_time = me->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");
	i=sizeof(notes)-me->query("LastReadNews");
	if( !pointerp(notes) || !sizeof(notes) )
	return notify_fail(WHT"�����羫�顿���������Բ��𣬡������񻰡�Ŀǰû���κ����š���\n"NOR);
	if( !arg ) 
	{
		if(i>10) write("����� Help news ���鿴����������ϵͳ��ʹ�÷�����\n"); 
		write(WHT"�����羫�顿"NOR"���������������񻰡�Ŀǰ����"+WHT+chinese_number(sizeof(notes))+NOR"������"+((i==0)? "��":"������"+YEL+chinese_number(i)+NOR"����δ������")+"\n");return 1; }
		if( arg=="all") // ��ʾ��������
		{
			msg = CYN"\n��"YEL"���������������������ũ���������������������������������������������������"CYN"��\n"NOR;
			notes = query("notes");
			
			if (mapp(last_read_time)) last_time_read = last_read_time[myid];
			for(i=sizeof(notes)-1 ; i>-1 ; i--)
			{
				msg += sprintf("%s"WHT"��"NOR"%3d"WHT"��" NOR,
				notes[i]["time"] > last_time_read ? YEL: "", i+1);
				msg += sprintf("     %-=25s %18s (%s)\n",
					notes[i]["title"], notes[i]["author"],
					RTIME_D->chinese_time(5, ctime(notes[i]["time"])));
			}
			msg += CYN"��"YEL"�������������������������������������������������������������񻰩�����������"CYN"��"NOR;
			me->start_more(msg);
			return 1;
			
		}
		else
		if ( arg=="new" )  // ��ʾ��������
		{
			if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
				num = 1;
			else
				for(num = 1; num<=sizeof(notes); num++)
					if( notes[num-1]["time"] > last_read_time[myid] ) break;
		} else if( !sscanf(arg, "%d", num) )
		
	return notify_fail("�㵽��Ҫ���ڼ�������ѽ��\n");
	
	if( num < 1 || num > sizeof(notes) )
		return notify_fail("������㣬����û����������Ү��\n");
		
	num--;
	me->start_more(sprintf("\n\n%s\n"RED"�������⣺"YEL"%s\n"WHT"������ʦ��"NOR"%s\n"GRN"����ʱ�䣺%s\n"CYN
	"��"YEL"�����������������ŷ�����������������������������������������������"CYN"��\n"NOR,
                CYN"���ǡ������񻰡�Ȫ��ʦ����վ�ĵ�"+chinese_number(num + 1)+"�����š�"NOR, 
		notes[num]["title"], notes[num]["author"], 
		"/cmds/usr/ttime"->chinese_time(5, ctime(notes[num]["time"])))
		+ notes[num]["msg"]+
	CYN"��"YEL"�����������������������������������������������������񻰩�����������"CYN"��"NOR, );

	if( !mapp(last_read_time) )
		me->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else 
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];

	if(me->query("LastReadNews") < num + 1)
		me->set("LastReadNews",num+1);

	return 1;
}

void init()
{
	object me=this_player();
// ֻ��apprentice�������ϵ���ʦ�޸�����
       if (wizardp(me) &&  wiz_level(me) > wiz_level("(apprentice)") )
	{
		//add_action("do_post", "newspt");//�������ר�����������
		add_action("do_post", "post");
		add_action("do_discard", "discard");
      }	
}

void done_post(object me, mapping note, string text)
{
	mapping *notes;

	note["time"] = time();
	note["msg"] = text;
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	if( sizeof(notes) > query("capacity"))
		notes = notes[query("capacity")/2 .. query("capacity")];

	set("notes", notes);
	save();
	restore();
// ʹ��channel��ʾ��ʾ������������
	CHANNEL_D->do_channel(me, "sjsh", BLINK YEL"�������񻰡��������ŷ�������λ������� news �鿴��\n\n" NOR);
	tell_object(me, "���ŷ�����ϡ�\n");
	return;
}

int help(object me)
{
    write(@HELP
�������񻰡�����ϵͳָ�� 

ָ���ʽ :
news                    �鿴���еĺ����·��������š�
news all                ģ�⻪������һ���� 
news new                �Ķ����µ����š� 
news <���ű��>         �鿴�˱�����ŵ���ϸ���ݡ�
post <��������>         ��ʦ�����������š�
discard <���>          ɾ��ָ����ŵ����š�����ʦר�ã�
 
HELP
    );
    return 1;
}
