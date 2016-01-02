namespace Part\Statement;

class Main {
				/**
				 * Load all statement
				 */

				private static function loader(plang) {
				var statement;
				let statement = new Main();
				let plang = statement->switch_statement(plang);
				let plang = statement->while_statement(plang);
				let plang = statement->if_statement(plang);
				let plang = statement->for_statement(plang);
				return plang;
				}

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
				private static function switch_statement(plang){
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
				private static function while_statement(plang){
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
				private static function if_statement(plang){
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
				private static function for_statement(plang){
				let plang = preg_replace("/for\((.*)\)/", "for($1){", plang);
				let plang = preg_replace("/for \((.*)\)/", "for($1){", plang);
				let plang = preg_replace("/foreach(.*)/", "foreach $1 {", plang);
				return plang;
				}

}
