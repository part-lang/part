namespace Part\Statement;

class Main {
	/**
	 * Switch statement usage:
	 *<code>
	 *      switch (statement)
	 *
	 *      case "1"
	 *      print "Hello"
	 *      break
	 * 
	 *      end
	 *</code>
	 */
    public function switch_statement(plang){
	let plang = preg_replace("/switch(.*)/", "switch $1 {", plang);
    let plang = preg_replace("/case(.*)/", "case $1:", plang);
	let plang = preg_replace("/break/", "break;", plang);
	return plang;
	}
	
	/**
	 * While statement usage:
	 *<code>
	 *      while (statement)
	 *
	 *      end
	 *</code>
	 */
    public function while_statement(plang){
	let plang = preg_replace("/while(.*)/", "while $1 {", plang);
	return plang;
	}
	
	/**
	 * IF statement usage:
	 *<code>
	 *      if (statement)
	 *		else
	 *      end
	 *</code>
	 */
    public function if_statement(plang){
	let plang = preg_replace("/if(.*)/", "if $1 {", plang);
    let plang = preg_replace("/elseif(.*)/", "} elseif $1 {", plang);
    let plang = preg_replace("/else/", "}else{", plang);
    let plang = preg_replace("/end/", "}", plang);
	return plang;
	}
	
	/**
	 * For & Foreach statement usage:
	 *<code>
	 *      for (statement)
	 *		
	 *      end
	 *
	 *		foreach (statement)
	 *
	 *		end
	 *</code>
	 */
    public function for_statement(plang){
	let plang = preg_replace("/for\((.*)\)/", "for($1){", plang);
	let plang = preg_replace("/for \((.*)\)/", "for($1){", plang);
    let plang = preg_replace("/foreach(.*)/", "foreach $1 {", plang);
	return plang;
	}

}