// news.c
// 需要修改的文件有

#include <ansi.h>;
inherit BULLETIN_BOARD;

void create()
{
	set_name("三界神化新闻板", ({ "newsboard"}) );
	set("location", "/d/wiz/jobroom"); 
	set("board_id", "newsall_b");  
	setup();
	set("capacity", 500);
}

// 这个部份是用来在login时调用的。
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
		
		if(i < 6 && i > 0) // 小于6条新闻才显示标题，不然会FLOOD
		{
			msg =CYN"\n≡"YEL"────三界神话最新新闻──────────────────────────"CYN"≡\n"NOR;
			
			if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
				num = 1;
				
			else
				for(num = 1; num<=sizeof(notes); num++)
					if( notes[num-1]["time"] > last_read_time[myid] ) break;
					
			if (mapp(last_read_time)) last_time_read = last_read_time[myid];
			for(i=sizeof(notes)-1 ; i>num-2 ; i--)
			{
				msg += sprintf(YEL"【"NOR"%3d"YEL"】"NOR,i+1);
				msg += sprintf("     %-=25s %18s (%s)\n",
					notes[i]["title"], notes[i]["author"],
					RTIME_D->chinese_time(5, ctime(notes[i]["time"])));
			}
			
			msg += CYN"≡"YEL"────────────────────────────三界神话──────"CYN"≡"NOR;
			me->start_more(msg);
		}
		
		i=sizeof(notes)-me->query("LastReadNews");
		write(BRED YEL"【三界精灵】告诉您：从您上次看新闻到现在"+((i==0)? "没有任何":"共有"+WHT+chinese_number(i)+YEL"条")+"新闻！\n"NOR);
		if(i>10) write("你可以Help news 来查看【三界新闻】的查看方法。\n"); // 提醒不知道有NEWS系统的玩家使用news
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
	return notify_fail(WHT"【三界精灵】告诉您：对不起，「三界神话」目前没有任何新闻。）\n"NOR);
	if( !arg ) 
	{
		if(i>10) write("你可以 Help news 来查看三界神话新闻系统的使用方法。\n"); 
		write(WHT"【三界精灵】"NOR"告诉您：「三界神话」目前共有"+WHT+chinese_number(sizeof(notes))+NOR"条新闻"+((i==0)? "。":"，您有"+YEL+chinese_number(i)+NOR"条尚未收听。")+"\n");return 1; }
		if( arg=="all") // 显示所有新闻
		{
			msg = CYN"\n≡"YEL"────三界神话所有新闻──────────────────────────"CYN"≡\n"NOR;
			notes = query("notes");
			
			if (mapp(last_read_time)) last_time_read = last_read_time[myid];
			for(i=sizeof(notes)-1 ; i>-1 ; i--)
			{
				msg += sprintf("%s"WHT"【"NOR"%3d"WHT"】" NOR,
				notes[i]["time"] > last_time_read ? YEL: "", i+1);
				msg += sprintf("     %-=25s %18s (%s)\n",
					notes[i]["title"], notes[i]["author"],
					RTIME_D->chinese_time(5, ctime(notes[i]["time"])));
			}
			msg += CYN"≡"YEL"────────────────────────────三界神话──────"CYN"≡"NOR;
			me->start_more(msg);
			return 1;
			
		}
		else
		if ( arg=="new" )  // 显示最新新闻
		{
			if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
				num = 1;
			else
				for(num = 1; num<=sizeof(notes); num++)
					if( notes[num-1]["time"] > last_read_time[myid] ) break;
		} else if( !sscanf(arg, "%d", num) )
		
	return notify_fail("你到底要看第几条新闻呀？\n");
	
	if( num < 1 || num > sizeof(notes) )
		return notify_fail("看清楚点，好像没有这条新闻耶。\n");
		
	num--;
	me->start_more(sprintf("\n\n%s\n"RED"新闻主题："YEL"%s\n"WHT"新闻巫师："NOR"%s\n"GRN"新闻时间：%s\n"CYN
	"≡"YEL"────三界神话新闻发布──────────────────────"CYN"≡\n"NOR,
                CYN"这是「三界神话」泉州师大总站的第"+chinese_number(num + 1)+"条新闻。"NOR, 
		notes[num]["title"], notes[num]["author"], 
		"/cmds/usr/ttime"->chinese_time(5, ctime(notes[num]["time"])))
		+ notes[num]["msg"]+
	CYN"≡"YEL"────────────────────────三界神话──────"CYN"≡"NOR, );

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
// 只给apprentice级别以上的巫师修改新闻
       if (wizardp(me) &&  wiz_level(me) > wiz_level("(apprentice)") )
	{
		//add_action("do_post", "newspt");//可以添加专用命令发布新闻
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
// 使用channel显示提示有了最新新闻
	CHANNEL_D->do_channel(me, "sjsh", BLINK YEL"【三界神话】最新新闻发布！各位玩家请用 news 查看。\n\n" NOR);
	tell_object(me, "新闻发表完毕。\n");
	return;
}

int help(object me)
{
    write(@HELP
「三界神话」新闻系统指令 

指令格式 :
news                    查看共有的和最新发布的新闻。
news all                模拟华附新闻一览。 
news new                阅读最新的新闻。 
news <新闻编号>         查看此编号新闻的详细内容。
post <新闻主题>         巫师发布主题新闻。
discard <编号>          删除指定编号的新闻。（巫师专用）
 
HELP
    );
    return 1;
}
