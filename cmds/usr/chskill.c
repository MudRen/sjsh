// chskill.c
// Modified by Cody May.2001


#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "初学乍练" NOR,BLU "初窥门径" NOR,HIB "粗通皮毛" NOR,HIB "略知一二" NOR,
        YEL "半生不熟" NOR,YEL "马马虎虎" NOR,HIY "已有小成" NOR,HIY "渐入佳境" NOR,
        HIM "驾轻就熟" NOR,HIM "了然于胸" NOR,HIR "出类拔萃" NOR,HIR "心领神会" NOR,
        MAG "神乎其技" NOR,MAG "出神入化" NOR,CYN "豁然贯通" NOR,CYN "登峰造极" NOR,
        HIC "举世无双" NOR,HIC "一代宗师" NOR,HIC "震古铄今" NOR,HIW "深不可测" NOR
});

string *knowledge_level_desc = ({
        BLU "新学乍用" NOR,HIB "初窥门径" NOR,HIB "略知一二" NOR,YEL "马马虎虎" NOR,
        YEL "已有小成" NOR,CYN "心领神会" NOR,CYN "了然于胸" NOR,CYN "豁然贯通" NOR,
        HIC "举世无双" NOR,HIC "震古铄今" NOR,HIW "深不可测" NOR
});
mapping valid_type = ([
"unarmed":      "扑击格斗之技","spells":      "法术",
"claw":         "爪功","cuff":         "拳功",
"finger":       "指功","strike":       "掌功",
"hand":         "手功","leg":          "腿功",
"sword":        "基本剑术","blade":        "基本刀法",  
"dagger":       "短兵刃","brush":        "笔法",                
"spear":        "基本枪法","hook":         "钩法",              
"stick":        "基本棍法","staff":        "基本杖法",          
"club" :        "棍法","throwing":     "暗器使用",              
"whip":         "基础鞭术","axe":          "基本斧法",
"hammer":       "基本锤法","force":        "内功心法",  
"dodge":        "基本轻功","parry":        "拆招卸力之法",      
]);

string skill_level(string, int);
string skill_enables(object sk);

int sort_skill(string file)
{
        int i;
        if ( !sscanf(file, "%*s.c") )  return 0;
        i = strlen(file);
        while(i--){
                if( file[i] == '.' ) continue;
                if( file[i] < 'a' || file[i] > 'z' )
                        return 0;
        }

        return 1;
}

int main(object me, string arg)
{
        mapping lrn;
        string exert, str, *file;
        object sk;
        int i, j = 0;

        seteuid(getuid());

        if(!arg) return notify_fail("指令格式 : chskill [武功名称]\n");
        
        sscanf("%s", arg);
                
        if(!me->query_skill(arg, 1)) 
                return notify_fail("你要查对什么技能？\n");
        
        if(file_size(SKILL_D(arg)+".c") < 1)
                return notify_fail("错误！你要查对技能文件已经消失，请通知巫师。\n");
        

        lrn = me->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
        str = sprintf("\n┌%-24s────────────────────────┐\n", HIW"【"+to_chinese(arg)+"功能表】"NOR);
        
        str = replace_string(str, "  ", "─");
        str += sprintf("│"HIY"等级"NOR"：  %s %3d/%6d\t      "HIY"类别"NOR"：  %-15s%9s  \n",skill_level(SKILL_D(arg)->type(), 
                        me->query_skill(arg, 1)), me->query_skill(arg, 1), 
                        (int)lrn[arg], SKILL_D(arg)->type(), "│");     
        
        if(member_array(arg, keys(valid_type))!=-1) 
//          (SKILL_D(arg)->type() != "magic" 
                return notify_fail(str+"└─────────────────────────────────┘\n");
                
        str += "│\t\t\t\t\t\t\t\t    │\n";
        sk = load_object(SKILL_D(arg));
        exert = skill_enables(sk);
        if(exert != ""){
                str += exert;
                i++;
        }
        
        if( stringp(exert = SKILL_D(arg)->exert_function_file("")) ){
                file = get_dir(exert);
                if( sizeof(file) > 0){
                        file  = filter_array(file, (: sort_skill :) );
                        j = sizeof(file);
                }
        }
        
        if(j && j > 0){
                if( i )
                        str = str + "├─────────────────────────────────┤\n";
                str += "│"HIG"内功方面(exert + )"NOR"：\t\t\t\t\t\t    ";
                for(i=0; i < j; i++){
                        if (i % 4 == 0) str += "│\n│\t";
                        str += sprintf("%-14s ",YEL+replace_string(file[i], ".c", "")+NOR);
                        if ( i > j-2 ){
                                switch(i%4){
                                        case 0: str +="\t\t\t\t\t            "; break;
                                        case 1: str +="\t\t\t            "; break;
                                        case 2: str +="\t\t    "; break;
                                        default: break;
                                }
                        }
                }
                str += "│\n";
                j = 0;
        }
        
        if( stringp(exert = SKILL_D(arg)->perform_action_file(""))){
                file = get_dir(exert);
                if( sizeof(file) > 0){
                        file  = filter_array(file, (: sort_skill :) );
                        j = sizeof(file);
                }
        }
        
        if(j && j > 0){
                if( i )
                        str = str + "├─────────────────────────────────┤\n";
                str += "│"HIG"外功方面(perform + )"NOR"：\t\t\t\t\t    ";
                for(i=0; i < j; i++){
                        if (i % 4 == 0) str += "│\n│\t";
                        str += sprintf("%-14s ",WHT+replace_string(file[i], ".c", "")+NOR);
                        if ( i > j-2 ){
                                switch(i%4){
                                        case 0: str +="\t\t\t\t            "; break;
                                        case 1: str +="\t\t            "; break;
                                        case 2: str +="\t    "; break;
                                        default: break;
                                }
                        }
                }
                str += "│\n";
                j = 0;
        }

        if( stringp(exert = SKILL_D(arg)->cast_spell_file("")) ){
                file = get_dir(exert);
                if( sizeof(file) > 0){
                        file  = filter_array(file, (: sort_skill :) );
                        j = sizeof(file);
                }
        }
        
        if(j && j > 0){
                if( i )
                        str = str + "├─────────────────────────────────┤\n";
                str += "│"HIG"妖术方面(cast + )"NOR"：\t\t\t\t\t\t    ";
                for(i=0; i < j; i++){
                        if (i % 4 == 0) str += "│\n│\t";
                        str += sprintf("%-14s ",HIC+replace_string(file[i], ".c", "")+NOR);
                        if ( i > j-2 ){
                                switch(i%4){
                                        case 0: str +="\t\t\t\t\t            "; break;
                                        case 1: str +="\t\t\t            "; break;
                                        case 2: str +="\t\t    "; break;
                                        default: break;
                                }
                        }
                }
                str += "│\n";
        }


        str += "└─────────────────────────────────┘\n";
        write(str);
        return 1;
}



string skill_enables(object sk)
{
        int i, j;
        string str, *skills;
        skills = keys(valid_type);
        
        for(i=0; i < sizeof(skills); i++) {
                if (sk->valid_enable(skills[i])) continue;
                skills[i] = 0;
        }
        
        skills -= ({ 0 });
        j = sizeof(skills);
        if( !j || j < 1)
                return "";
        str = "│"HIM"特殊技能"NOR"：\t\t\t\t\t\t\t    ";
                
        for(i=0; i < j; i++) {
                if (i % 4 == 0) str += "│\n│\t";
                str += sprintf("%-14s ", HIC+valid_type[skills[i]]+"("+skills[i]+")"NOR);
                if ( i > j-2 ){
                        switch(i%4){
                                case 0: str +="\t\t\t\t            "; break;
                                case 1: str +="\t\t            "; break;
                                case 2: str +="\t    "; break;
                                default: break;
                        }
                }
        }
        str += "│\n";
        return str;
}

string skill_level(string type, int level)
{
        int grade;
        
        switch(type) {
                case "knowledge":
                        grade = level / 15;
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        grade = level / 15;
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
        write("\n指令格式 : chskill [武功名称]\n");
        write(@HELP
这个指令可以让你查询此项技能的功能和数据。

特殊技能表示可以 enable 的技能。

内功方面显示可运用(exert)的内功。

外功方面显示可使用(perform)的外功。

妖术方面显示可运用(cast)的妖术。      
HELP);

    return 1;
}
