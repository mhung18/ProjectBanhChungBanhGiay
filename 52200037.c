#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.1415926535

int main ()
{
    int n,dc,dg,ld,bc,bg;
    char w[10];
    float nd;
    FILE *input;
    input = fopen("input.inp", "r");
    fscanf(input,"%d%d%d%d%s",&n,&dc,&dg,&ld,w);
    fclose(input);
    FILE *output;
    output = fopen("output.out","w");
    if (n <= 0 || n > 1000 || ld < 0 || ld > 1000){
        bc = -1;
        bg = -1;
        nd = n;
        fprintf(output,"%d %d %.3f",bc, bg, nd);
	}
	else if (dc <= 0 || dg <= 0){
		if (dc <= 0 && dg <=0){
			bc = 0;
			bg = 0;
			nd = n;
			fprintf(output,"%d %d %f",bc ,bg ,nd);
		}
		else if (dc <= 0){
			bc = 0;
			bg = n/((dg*dg*PI)/4);
			nd = n - bg*((dg*dg*PI)/4);
			fprintf(output,"%d %d %f",bc, bg, nd);
		}
		else{
			bg = 0;
			bc = n/(dc*dc);
			nd = n - bc*dc*dc;
			fprintf(output,"%d %d %f",bc, bg, nd);
		}
	}
    
    else{
        if (strcmp(w,"Wind") == 0){
            float nepdung;
            bc = n/(dc*dc);
            bg = (n % (dc*dc))/((dg*dg*PI)/4);
            nepdung = (dc*dc)*bc + ((dg*dg*PI)/4)*bg;
            nd = n - nepdung;
            if (bc + bg > ld){
            	if (bc > ld){
            		bc = ld;
				}
            	else {
					bg = ld - bc;
				}
			}
            fprintf(output,"%d %d %.3f",bc, bg, nd);
        }
        else if (strcmp(w,"Rain") == 0){
			bc = n/(dc*dc + (dg*dg*PI)/4);
			bg = bc;
			nd = n - dc*dc*bc - ((dg*dg*PI)/4)*bg;
			if (nd >= dc*dc || nd >= (dg*dg*PI)/4){
				if (bg + bg < ld){
				float nd1;
				float nd2;
				int bclamthem, bglamthem;
				bclamthem = nd/(dc*dc);
				bglamthem = nd/((dg*dg*PI)/4);
				nd1 = nd - bclamthem*(dc*dc);
				nd2 = nd - bglamthem*((dg*dg*PI)/4);
					if (nd1 < nd2){
						bc = bc + bclamthem;
						nd = nd1;
						fprintf(output,"%d %d %.3f",bc, bg, nd);
					}
					else{
						bg = bg + bglamthem;
						nd = nd2;
						fprintf(output,"%d %d %.3f",bc, bg, nd);
					}	
				}
				//bc + bg > ld
				else{
					bc = ld/2;
					bg = ld/2;
					if (ld % 2 == 0){
						fprintf(output,"%d %d %.3f",bc, bg, nd);
					}
					else {
						if (dc*dc > (dg*dg*PI)/4){
							bc += 1;
							fprintf(output,"%d %d %.3f",bc, bg, nd);
						}
						else{
							bg += 1;
							fprintf(output,"%d %d %.3f",bc, bg, nd);
						}
					}
					
				}
				
			}
			else{
				if (bc + bg <= ld){
					fprintf(output,"%d %d %.3f",bc, bg, nd);
				}
				else {
					bc = ld/2;
					bg = ld/2;
					if (ld % 2 == 0){
						fprintf(output,"%d %d %.3f",bc, bg, nd);
					}
					else {
						if (dc*dc > (dg*dg*PI)/4){
							bc += 1;
							fprintf(output,"%d %d %.3f",bc, bg, nd);
						}
						else{
							bg += 1;
							fprintf(output,"%d %d %.3f",bc, bg, nd);
						}
					}
				}
				
			}
        }
        else if (strcmp(w,"Sun") == 0){
            int G,H;
            G = dc % 6;
            H = ld % 5;
            if (G == H){
                n = round(n + n*0.05) ;
                ld = ld - 5 ;
            } 
			else if(G == H + 1){
                n = round(n + n*0.07) ;
                ld = ld - 7 ;
            }
            else if(G == H + 2 || H == G + 4){
                n = round(n + n*10) ;
                ld = ld - 0.1;
            }   
            else if(G == H + 3 || H == G + 3){
                n = round(n + n*0.12);
                ld = ld - 12;
            }
            else if(G == H + 4 || H == G + 2){
                n = round(n + n*0.15);
                ld = ld - 15;
            }
            else {
                n = n + n*0.2;
                ld = ld - 20;
            }
            
            if ((dc + dg) % 3 == 0){
            	bc = n/(dc*dc + (dg*dg*PI)/4);
				bg = bc;
				nd = n - dc*dc*bc - ((dg*dg*PI)/4)*bg;
				if (nd >= dc*dc || nd >= (dg*dg*PI)/4){
					if (bg + bg < ld){
						float nd1;
						float nd2;
						int bclamthem, bglamthem;
						bclamthem = nd/(dc*dc);
						bglamthem = nd/((dg*dg*PI)/4);
						nd1 = nd - bclamthem*(dc*dc);
						nd2 = nd - bglamthem*((dg*dg*PI)/4);
						if (nd1 < nd2){
							bc = bc + bclamthem;
							nd = nd1;
						}
						else{
							bg = bg + bglamthem;
							nd = nd2;
						}	
					}
					else{
						bc = ld/2;
						bg = ld/2;
						if (ld % 2 == 0){
							fprintf(output,"%d %d %.3f",bc, bg, nd);
						}
						else {
							if (dc*dc > (dg*dg*PI)/4){
								bc += 1;
								fprintf(output,"%d %d %.3f",bc, bg, nd);
							}
							else{
								bg += 1;
								fprintf(output,"%d %d %.3f",bc, bg, nd);
							}
						}
					}
				}
			
				else{
					if (bc + bg <= ld){
						fprintf(output,"%d %d %.3f",bc, bg, nd);
					}
					else {
						bc = ld/2;
						bg = ld/2;
						if (ld % 2 == 0){
							fprintf(output,"%d %d %.3f",bc, bg, nd);
						}
						else {
							if (dc*dc > (dg*dg*PI)/4){
								bc += 1;
								fprintf(output,"%d %d %.3f",bc, bg, nd);
							}
							else{
								bg += 1;
								fprintf(output,"%d %d %.3f",bc, bg, nd);
							}
						}
					}
				}
			}
			
			else if ((dc + dg) % 3 == 1){
				float nepdung;
            	bc = n/(dc*dc);
            	bg = (n % (dc*dc))/(((dg*dg)*PI)/4);
            	nepdung = (dc*dc)*bc + ((dg*dg*PI)/4)*bg;
            	nd = n - nepdung;
            	if (bc + bg > ld){
            		if (bc > ld){
            			bc = ld;
					}
            		else {
						bg = ld - bc;
					}
				}
            	fprintf(output,"%d %d %.3f",bc, bg, nd);
			}
            else {
            	if (n == 220 && ld == 284 || n == 284 && ld == 220){
            	    bc = 0;
            	    bg = 0;
                	nd = n;
                	fprintf(output,"%d %d %.3f",bc, bg, nd);
            	} 
            	else {
                	bg = n/((dg*dg*PI)/4);
                	float nepdung;
                	nepdung = bg*((dg*dg*PI)/4);
                	nd = n - nepdung;
                	bc = nd/(dc*dc);
                	if (bc + bg > ld){
            			if (bg > ld){
            				bg = ld;
            				bc = 0;
            				nd = n - ((dg*dg*PI)/4)*bg;
						}
						else {
							bc = ld - bg;
							nd = n - (dc*dc)*bc - ((dg*dg*PI)/4)*bg;
						}
					}
                	fprintf(output,"%d %d %.3f",bc, bg, nd);
            	}
            	
			}
    
        }
        else if (strcmp(w,"Cloud") == 0){
            if (n == 220 && ld == 284 || n == 284 && ld == 220){
                bc = 0;
                bg = 0;
                nd = n;
                fprintf(output,"%d %d %.3f",bc, bg, nd);
            } 
            else {
                bg = n/((dg*dg*PI)/4);
                float nepdung;
                nepdung = bg*((dg*dg*PI)/4);
                nd = n - nepdung;
                bc = nd/(dc*dc);
                if (bc + bg > ld){
            		if (bg > ld){
            			bg = ld;
            			bc = 0;
            			nd = n - ((dg*dg*PI)/4)*bg;
					}
					else {
						bc = ld - bg;
						nd = n - (dc*dc)*bc - ((dg*dg*PI)/4)*bg;
					}
				}
                fprintf(output,"%d %d %.3f",bc, bg, nd);
            }

        }
        else if (strcmp(w,"Fog") == 0){
        	bc = dc;
        	bg = dg;
            nd = n;
            fprintf(output,"%d %d %.3f",bc, bg, nd); 
        }
    fclose(output);
    }
}
