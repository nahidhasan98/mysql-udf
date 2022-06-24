/*
 * Nahid Hasan
 * mysql UDF
 * 25 Jun, 2022
 */
 
DROP FUNCTION IF EXISTS run_cmd;

CREATE FUNCTION run_cmd RETURNS string SONAME 'nahid_udf.so';